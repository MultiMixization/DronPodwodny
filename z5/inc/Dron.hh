#ifndef DRON_HH
#define DRON_HH

#define ACCELERATION 0.01
#define ANGLEACCELERATION 0.2

#include <unistd.h>
#include <ncurses.h>
#include <sys/select.h>
#include <math.h>

#include "Punkt.hh"
#include "Wektor3D.hh"
#include "Dr3D_gnuplot_api.hh"
#include "Prostopadloscian.hh"
#include "DronInterface.hh"
#include "gran8kat.hh"
#include "Przeszkoda.hh"

class Dron : public Prostopadloscian, public DroneInterface, public Przeszkoda{
protected:
  
  /*!
   * \brief speed forward
   */
  double PredkoscPrzod;
  
  /*!
   * \brief speed arround stationary axis y
   */
  double PredkoscPitch;
  
  /*!
   * \brief speed arround stationary axis z
   */
  double PredkoscYaw;
  
  /*!
   * \brief speed arround stationary axis x
   */
  double PredkoscRoll;

  /*!
   * \brief left propeller
   */
  gran8kat Sruba1;
  
  /*!
   * \brief right propeller
   */
  gran8kat Sruba2;

  //gran8kat Plywak1;    //Z jakiegos powodu dodanie kolejnej figury rozwala pozastale i powoduje stack smashing
  //gran8kat Plywak2;

  /*!
   * \brief vector leading from the middle of the body to an attachment point of a propeller 1
   */
  Wektor3D WekSruba1;
  
  /*!
   * \brief vector leading from the middle of the body to an attachment point of a propeller 1
   */
  Wektor3D WekSruba2;

  //Wektor3D WekPlywak1;
  //Wektor3D WekPlywak2;

  /*!
   * \brief draws propeller 1 position according to current yaw, pitch, roll and body position
   */
  void rysSrb1();

  /*!
   * \brief draws propeller 2 position according to current yaw, pitch, roll and body position
   */
  void rysSrb2();

  //void rysPlywak1();
  //void rysPlywak2();

public:
  
  /*!
   * \brief Constructor
   * \param A - poiner on api
   */
  Dron(std::shared_ptr<drawNS::Draw3DAPI> A, Punkt S, MacierzObr O);

  /*!
   * \brief Destructor
   */
  ~Dron() {wymaz();}
  
  /*!
   * \brief Setter - Forward speed
   * \param P - Forward speed
   */
  void setPredkoscPrzod(double P) override {PredkoscPrzod=P;}

   /*!
   * \brief Getter - Forward speed
   * \return Forward speed
   */
  double getPredkoscPrzod() override {return PredkoscPrzod;}

  /*!
   * \brief Setter - Pitch speed
   * \param P - Pitch speed
   */
  void setPredkoscPitch(double P) {PredkoscPitch=P;}

  /*!
   * \brief Getter - Pitch speed
   * \return Pitch speed
   */
  double getPredkoscPitch() const {return PredkoscPitch;}

  /*!
   * \brief Setter - Yaw speed
   * \param P - Yaw speed
   */
  void setPredkoscYaw(double P) {PredkoscYaw=P;}

  /*!
   * \brief Getter - Yaw speed
   * \return Yaw speed
   */
  double getPredkoscYaw() const {return PredkoscYaw;}

  /*!
   * \brief Setter - Roll speed
   * \param P - Roll speed
   */
  void setPredkoscRoll(double P) {PredkoscRoll=P;}

  /*!
   * \brief Getter - Roll speed
   * \return Roll speed
   */
  double getPredkoscRoll() const {return PredkoscRoll;}

  /*!
   * \brief changes the speed in direction defined by the char
   * \param znak - char defining the direction of applied acceleration
   */
  void ruch(char znak) override;

  /*!
   * \brief draws the body and the propellers
   */
  void rysujAll() override;

  /*!
   * \brief erases the body and the propellers
   */
  void wymaz() override;

  /*!
   * \brief updates the body and propellers position according to speed, roll, yaw and pitch
   */
  void updatePosition() override;

  double getSrednica() override {return referencyjny.dlugosc();}

  Punkt getSrodek() override {return Obiekt3D::getSrodek();}

  bool Kolizja(std::shared_ptr<DroneInterface> IntDron) override;
};

#endif
