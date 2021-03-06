#ifndef DRON_HH
#define DRON_HH

#define ACCELERATION 0.02
#define ANGLEACCELERATION 1

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

  MacierzObr angleRotation;

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
  void setPredkoscPrzod(const double P) override {PredkoscPrzod=P;}

   /*!
   * \brief Getter - Forward speed
   * \return Forward speed
   */
  double getPredkoscPrzod() override {return PredkoscPrzod;}

  /*!
   * \brief Setter - Rotation matrix in one frame
   * \param M - Rotation Matrix
   */
  void setAngleRotation(const MacierzObr M) {angleRotation=M;}

  /*!
   * \brief Getter - Rotation matrix in one frame
   * \return Rotation Matrix
   */
  MacierzObr getAngleRotation() const {return angleRotation;}

  /*!
   * \brief changes the speed in direction defined by the char
   * \param znak - char defining the direction of applied acceleration
   */
  void ruch(const char znak) override;

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

  /*
   * \brief Getter - Longest vector begining at the center of Drone and ending at its body
   */
  double getSrednica() override {return referencyjny.dlugosc();}

  /*
   * \brief Getter - Center of drone
   * \return Center oof drone
   */
  Punkt getSrodek() override {return Obiekt3D::getSrodek();}

  /*
   * \brief Checks if there is a collision with an obstacle
   * \return ix collision present
   */
  bool Kolizja(std::shared_ptr<DroneInterface> IntDron) override;
};

#endif
