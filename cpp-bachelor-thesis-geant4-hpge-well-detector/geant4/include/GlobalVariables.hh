#include "G4SystemOfUnits.hh"
#include <G4Types.hh>

// Geometry
inline G4double worldSize = 40 * cm; // World box
inline G4double global_A = 71.1 * mm;   // crystal length
inline G4double global_G = 9.0 * mm;     // endcap -> crystal gap (axial & radial)
inline G4double global_tCapTop = 2.0 * mm;    // 1
inline G4double global_zCrysTop = +0.5 * global_A;
inline G4double global_zCapTopInner = global_zCrysTop + global_G;   // inside surface facing crystal
inline G4double global_zCapTopOuter = global_zCapTopInner + global_tCapTop;  // outside surface

inline G4double global_E = 51.3 * mm;   // endcap well depth (outer top -> bottom of vacuum)
inline G4double global_zWellVacBot = global_zCapTopOuter - global_E;      // top outer -> depth

// inline G4double sourceDistance = 13 * cm;
// inline G4double sourceDistance = 2 * mm;
inline G4double sourceDistance = 25.65 * mm;

// inline G4double particleEnergy = 122. * keV;

// Histogram
inline G4int numberOfBins = 2000;
inline G4double xMin = 0.;
inline G4double xMax = 2. * MeV;