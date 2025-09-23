//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
/// \file B4/B4a/src/DetectorConstruction.cc
/// \brief Implementation of the B4::DetectorConstruction class

/*
Started from example B4a and made modifications.
*/

/*
HPGe Well Detector Geometry Description
Dimensions:
A (Crystal length): 71.1 mm
B (Crystal diameter): 56.8 mm => Rcrys = 28.4 mm
C (Crystal hole depth (from top)): 57.7 mm
D (Crystal hole diameter): 20.6 mm => Rhole = 10.3 mm
E (Endcap well depth (from outer top surface)): 51.3 mm
F (Endcap well diameter): 15.5 mm  => Rwell = 7.75 mm
G (Endcap-to-crystal radial/axial gap) = 9.0 mm (vacuum)

Wall / dead layers:
1 (Endcap top thickness): 2.0 mm [Al]
2 (Endcap side thickness): 1.6 mm [Al]
3 (Endcap well side thickness): 0.5 [Al]
4 (Endcap well bottom thickness): 2.0 mm [Al]
5 (Mount cup thickness (bottom)): 1.6 mm [Al] (behind crystal bottom)
6 (Crystal top & side dead layer: 0.7 mm [inactive Ge]
7 (Crystal hole (inner & bottom) dead): 0.3 um = 0.0003 mm [inactive Ge]

Geometry conventions
- z axis is vertical
- Crystal centre is at z = 0, so crystal extends from -A/2 to +A/2.
- The dead layer (6) coats the cylindrical side and the top face.
No appreciable dead layer on outer bottom face.
- The bore/hole (D, C) starts at the crystal top face (z = +A/2) and
goes downward (towards -z) a depth C.  Its inner surface (7) is
 a very thin dead (inactive) Ge layer.
 - The active volume = bulk Ge minus outer dead shell (t6) minus
inner dead shell (t7) and its bottom disk. Because the t7 layer is
extremely thin (0.3 µm), its' construction may be disabled by
setting kBuildBDead=false below to avoid precision issues.
- The endcap is an Al can surrounding the crystal with a vacuum gap G radially and
axially. We model a cylindrical body plus a coaxial narrow endcap well (for close
source counting) with its own side/bottom thicknesses (3,4). The well protrudes through
the endcap top toward the crystal. The inner well volume is air. The well does not penetrate
the crystal; it stops in the free space gap in front of the crystal top.
- A flat Al mount cup (5) is placed around the crystal.
- All placements are centred laterally so that the cylindrical axes coincide.

Coordinate checks (derived z values)
z_crysTop    = +A/2
z_crysBot    = -A/2
Hole bottom  = z_crysTop - C
Outer dead inactive Ge thickness t6 = 0.7 coats side full length and top only.
Inner inactive Ge thickness t7 = 0.0003
Active side radius   = Rcrys - t6
Active top starts at z_crysTop - t6
Active hole radius   = Rhole - t7
Active hole bottom   = Hole bottom + t7   (since t7 layer coats bottom)

Endcap dimensions (outer -> inner)
Endcap outer R = Rcrys + G + 2 (side Al thickness) = RoutCap
Endcap inner R = RoutCap - 2  = Rcrys + G (checks)
Endcap top outer surface at z = z_capTopOut = z_crysTop + G + 1(topThk)
Endcap top inner surface at z = z_capTopIn  = z_capTopOut - 1 = z_crysTop + G
(NB: label 1=2mm; we named local var tCapTop)
Endcap bottom outer surface at z = z_capBotOut = z_crysBot - 5 (mount cup thickness) - ???
For simplicity we make the sidewall a single extrusion long enough to cover the crystal
and gap and mount cup. We extend a little margin.
*/

#include "DetectorConstruction.hh"

#include "G4Material.hh"
#include "G4NistManager.hh"

#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4SubtractionSolid.hh"
#include "G4UnionSolid.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4PVReplica.hh"
#include "G4AutoDelete.hh"

#include "G4GeometryManager.hh"
#include "G4PhysicalVolumeStore.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4SolidStore.hh"

#include "G4VisAttributes.hh"
#include "G4Colour.hh"

#include "G4PhysicalConstants.hh"
#include "G4SystemOfUnits.hh"

#include "ActiveDetectorSD.hh"
#include "G4SDManager.hh"
#include "GlobalVariables.hh"

namespace B4
{

G4VPhysicalVolume* DetectorConstruction::Construct()
{
  // Define materials
  DefineMaterials();

  // Define volumes
  return DefineVolumes();
}

void DetectorConstruction::DefineMaterials()
{
  // Materials
  auto nistManager = G4NistManager::Instance();
  nistManager->FindOrBuildMaterial("G4_AIR");
  nistManager->FindOrBuildMaterial("G4_Ge");
  nistManager->FindOrBuildMaterial("G4_Al");

  // Vacuum
  G4double a;  // mass of a mole;
  G4double z;  // z=mean number of protons;
  G4double density;
  new G4Material("Galactic", z = 1., a = 1.01 * g / mole, density = universe_mean_density,
      kStateGas, 2.73 * kelvin, 3.e-18 * pascal);

  // Print materials
  G4cout << *(G4Material::GetMaterialTable()) << G4endl;
}

G4VPhysicalVolume* DetectorConstruction::DefineVolumes()
{
  // Geometry parameters
  G4double A  = 71.1*mm;   // crystal length
  G4double B  = 56.8*mm;   // crystal diameter
  G4double C  = 57.7*mm;   // hole depth from top
  G4double D  = 20.6*mm;   // hole diameter
  G4double E  = 51.3*mm;   // endcap well depth (outer top -> bottom of air)
  G4double F  = 15.5*mm;   // endcap well diameter
  G4double G = 9.0*mm;     // endcap -> crystal gap (axial & radial)

  G4double tCapTop   = 2.0*mm;    // 1
  G4double tCapSide  = 1.6*mm;    // 2
  G4double tWellSide = 0.5*mm;    // 3
  G4double tWellBot  = 2.0*mm;    // 4
  G4double tMount    = 1.6*mm;    // 5
  G4double t6        = 0.7*mm;    // 6
  G4double t7        = 0.0003*mm; // 7 (0.3 µm)

  G4double Rcrys = 0.5*B;
  G4double Rhole = 0.5*D;
  G4double Rwell = 0.5*F;

  // Derived radii for active regions
  G4double Ract  = Rcrys - t6;       // active outer radius
  G4double RhAct = Rhole - t7;        // active hole radius

  // z positions relative to crystal centre z = 0
  G4double zCrysTop = +0.5*A;
  G4double zCrysBot = -0.5*A;
  G4double zHoleBot = zCrysTop - C;

  // Active top plane (below t6 layer)
   G4double zActTop = zCrysTop - t6;
  // Active hole bottom plane (above t7 bottom)
  G4double zActHoleBot = zHoleBot + t7; // essentially same

  // Get materials
  auto vacuum = G4Material::GetMaterial("Galactic");
  auto air = G4Material::GetMaterial("G4_AIR");
  auto matGe = G4Material::GetMaterial("G4_Ge");
  auto matAl = G4Material::GetMaterial("G4_Al");

  if ( !vacuum || ! air || ! matGe || ! matAl ) {
    G4ExceptionDescription msg;
    msg << "Cannot retrieve materials already defined.";
    G4Exception("DetectorConstruction::DefineVolumes()",
      "MyCode0001", FatalException, msg);
  }

  //
  // World
  //
  auto worldS
    = new G4Box("World",           // its name
                 worldSize/2, worldSize/2, worldSize/2); // its size

  auto worldLV
    = new G4LogicalVolume(
                 worldS,           // its solid
                 air,           // its material
                 "World");         // its name

  auto worldPV = new G4PVPlacement(nullptr,  // no rotation
    G4ThreeVector(),                         // at (0,0,0)
    worldLV,                                 // its logical volume
    "World",                                 // its name
    nullptr,                                 // its mother  volume
    false,                                   // no boolean operation
    0,                                       // copy number
    fCheckOverlaps);                         // checking overlaps

  // 1. Aluminium Endcap Body (outer shell)
  // Inner radius of main cavity (vacuum region around crystal)
  G4double RcapInner = Rcrys + G;
  G4double RcapOuter = RcapInner + tCapSide;

  // Axial: we put a gap G above crystal top (to inner cap top), then cap top thickness
  G4double zCapTopInner = zCrysTop + G;           // inside surface facing crystal
  G4double zCapTopOuter = zCapTopInner + tCapTop;  // outside surface

  // Below the crystal we include mount gap negligible then Al mount cup tMount; we extend sidewall down to include that.
  G4double zMountTop = zCrysBot;                   // crystal sits directly on mount
  G4double zMountBot = zMountTop - tMount;         // bottom of mount cup (Al)
  // Sidewall outer bottom at same as mount bottom.

  // Build a simple hollow tube representing side+top (without boolean union to mount disc later)
  G4double hCapSide = (zCapTopOuter - zMountBot) / 2.;
  G4double zCapSideC = (zCapTopOuter + zMountBot) / 2.;

  auto capSideOuter = new G4Tubs("CapSideOuter",    // its name
                                 0.,                // its inner radius
                                 RcapOuter,         // its outer radius
                                 hCapSide,          // hz
                                 0.,                // its start angle
                                 twopi);            // its spanning angle

  // Inner carve should stop at the *inner* top surface (zCapTopInner),
  // leaving an aluminum lid of thickness tCapTop at the very top.
  const G4double hCapInner = (zCapTopInner - zMountBot) / 2.;
  const G4double zCapInnerC = (zCapTopInner + zMountBot) / 2.;
  auto capSideInner = new G4Tubs("CapSideInner", 0., RcapInner, hCapSide, 0., twopi);

  auto capBody = new G4SubtractionSolid("CapBody", capSideOuter, capSideInner,
      nullptr, G4ThreeVector(0, 0, zCapInnerC - zCapSideC));

  // Now punch the *top opening* of the well through the lid: diameter F (radius Rwell)
  const G4double zTopDiskC = 0.5 * (zCapTopInner + zCapTopOuter); // centre of top disk
  auto topHole = new G4Tubs("CapTopHole", 0., Rwell, tCapTop / 2., 0., twopi);
  auto capSide = new G4SubtractionSolid("CapSide",                                      // pName
                                        capBody,                                        // pSolidA
                                        topHole,                                        // pSolidB
                                        nullptr,                                        // rotMatrix
                                        G4ThreeVector(0, 0, zTopDiskC - zCapSideC));    // transVector

  // Mount cup is effectively just the bottom of the side tube (already present as side thickness). To thicken the true
  // bottom disk we union a solid disk of thickness tMount if tMount>tCapSide difference, but side tube already has
  // Al down to zMountBot.

  // 2. Endcap Well (narrow tube through top toward crystal)
  // The well protrudes downward from the outer top surface a total depth E.
  // So the well air bottom (inner) is at z = zCapTopOuter - E.
  G4double zWellVacBot = zCapTopOuter - E;      // top outer -> depth
  G4double zWellAlBot = zWellVacBot - tWellBot; // include bottom Al thickness

  // Build an Al tube (wall thickness tWellSide) closed by bottom thickness tWellBot.
  G4double RwellOuter = Rwell + tWellSide;
  G4double hWellTotal = (zCapTopOuter - zWellAlBot) / 2.;
  G4double zWellC = (zCapTopOuter + zWellAlBot) / 2.;

  auto wellOuter = new G4Tubs("WellOuter", 0., RwellOuter, hWellTotal, 0., twopi);
  // carve out inner air tube (length E) but leave bottom Al thickness tWellBot
  G4double hWellVac = E / 2.;
  auto wellInner = new G4Tubs("WellInnerVacCarve", 0., Rwell, hWellVac, 0., twopi);
  // position of the carve relative to well centre: The carve is centred halfway along the air region which spans zCapTopOuter-E/2 downward; relative shift = ( (zCapTopOuter - E/2) - zWellC )
  G4double zWellVacC = zCapTopOuter - E / 2.;
  G4double dzCarve = zWellVacC - zWellC;

  auto wellAl = new G4SubtractionSolid("EndcapWellAl",                      // pName
                                       wellOuter,                           // pSolidA
                                       wellInner,                           // pSolidB
                                       nullptr,                             // rotMatrix
                                       G4ThreeVector(0, 0, dzCarve));       // transVector

  // Union the well with the cap body
  auto capPlusWell = new G4UnionSolid("EndcapAl",                                   // pName
                                      capSide,                                      // pSolidA
                                      wellAl,                                       // pSolidB
                                      nullptr,                                      // rotMatrix
                                      G4ThreeVector(0, 0, zWellC - zCapSideC));     // transVector

  auto capLV = new G4LogicalVolume(capPlusWell, matAl, "EndcapAl_LV");
  new G4PVPlacement(nullptr, G4ThreeVector(0, 0, zCapSideC), capLV, "EndcapAl", worldLV, false, 0, fCheckOverlaps);

  // 3. Air inside endcap main cavity (excludes crystal, includes gap)
  // Cylinder from mount top (zCrysBot) up to cap top inner (zCapTopInner)
  G4double hCav = (zCapTopInner - zMountTop) / 2.;
  G4double zCavC = (zCapTopInner + zMountTop) / 2.;
  auto cavS = new G4Tubs("EndcapCavity", 0., RcapInner, hCav, 0., twopi);
  auto cavLV = new G4LogicalVolume(cavS, vacuum, "EndcapCavity_LV");
  auto cavPV = new G4PVPlacement(nullptr, G4ThreeVector(0, 0, zCavC), cavLV, "EndcapCavity", worldLV, false, 0, fCheckOverlaps);

  // 4. Air inside endcap WELL (for sources)
  // Cylinder of radius Rwell, length E. Centre at zWellVacC
  auto wellVacS = new G4Tubs("EndcapWellVac", 0., Rwell, E / 2., 0., twopi);
  auto wellVacLV = new G4LogicalVolume(wellVacS, air, "EndcapWellVac_LV");
  new G4PVPlacement(nullptr, G4ThreeVector(0, 0, zWellVacC), wellVacLV, "EndcapWellVac", worldLV, false, 0, fCheckOverlaps);

  // 5. HPGe CRYSTAL (bulk, including all dead)
  auto crysOuterCyl = new G4Tubs("HPGe_Outer", 0., Rcrys, A / 2., 0., twopi);
  auto crysHoleCyl = new G4Tubs("HPGe_Hole", 0., Rhole, C / 2., 0., twopi);
  // subtract hole starting at top -> shift carve upward relative to crystal centre
  G4double zHoleC = zCrysTop - C / 2.;
  auto crysWithHole = new G4SubtractionSolid("HPGe_CrystalSolid", crysOuterCyl, crysHoleCyl, nullptr, G4ThreeVector(0, 0, zHoleC));
  auto crysLV = new G4LogicalVolume(crysWithHole, matGe, "HPGe_Crystal_LV");
  // place in cavity (mother world for simplicity; overlaps with cavity vacuum so we must mother it to cavity)
  new G4PVPlacement(nullptr, {}, crysLV, "HPGe_Crystal", cavLV, false, 0, fCheckOverlaps);

  // 6. Outer t6-diffused dead layer volume (logical / scoring OFF)
  // Represent as a shell + top disk carved by hole. Because t6 coats side+top only,
  // we build a full-thickness shell then carve away bottom flush.
  auto t6_OuterCyl = new G4Tubs("HPGe_t6_outer", 0., Rcrys, t6 / 2., 0., twopi); // top disk thickness t6
  // create side shell: a cylinder of height A with thickness t6
  auto t6_SideOuter = new G4Tubs("HPGe_t6_sideOut", Ract, Rcrys, A / 2., 0., twopi);
  auto t6_SideUnion = new G4UnionSolid("HPGe_t6_topPlusSide", t6_SideOuter, t6_OuterCyl, nullptr, G4ThreeVector(0, 0, (A / 2.) - t6 / 2.));
  // carve the bore so t6 doesn't extend into hole
  auto t6_HoleCarve = new G4Tubs("HPGe_t6_holeCarve", 0., Rhole, C / 2., 0., twopi);
  auto t6_Solid = new G4SubtractionSolid("HPGe_t6_solid", t6_SideUnion, t6_HoleCarve, nullptr, G4ThreeVector(0, 0, zHoleC));
  auto t6_LV = new G4LogicalVolume(t6_Solid, matGe, "HPGe_t6_Dead_LV");
  new G4PVPlacement(nullptr, {}, t6_LV, "HPGe_t6_Dead", crysLV, false, 0, fCheckOverlaps);

  // 7. Inner t7 dead layer lining the hole + bottom patch
  G4bool kBuildBDead = true; // set false to suppress
  if (kBuildBDead) {
      // side lining thickness t7 along hole wall + bottom disk t7
      auto t7_Side = new G4Tubs("HPGe_t7_side", RhAct, Rhole, C / 2., 0., twopi);
      auto t7_Bot = new G4Tubs("HPGe_t7_bot", 0., Rhole, t7 / 2., 0., twopi);
      auto t7_Union = new G4UnionSolid("HPGe_t7_solid", t7_Side, t7_Bot, nullptr, G4ThreeVector(0, 0, (t7 / 2.) - (C / 2.)));
      auto t7_LV = new G4LogicalVolume(t7_Union, matGe, "HPGe_t7_Dead_LV");
      new G4PVPlacement(nullptr, G4ThreeVector(0, 0, zHoleC), t7_LV, "HPGe_t7_Dead", crysLV, false, 0, fCheckOverlaps);
  }

  // 8. Active HPGe volume  (Ge minus t6 minus t7)
  // Build from scratch to avoid reliance on daughter subtraction scoring.
  auto actOuter = new G4Tubs("HPGeAct_outer", 0., Ract, (A - t6) / 2., 0., twopi);
  // Active extends from zActTop down to zCrysBot, so half-height:
  G4double hAct = (zActTop - zCrysBot) / 2.;
  G4double zActC = (zActTop + zCrysBot) / 2.;
  auto actOuterCyl = new G4Tubs("HPGeActOuter2", 0., Ract, hAct, 0., twopi);
  // subtract active bore
  G4double hActHole = (zActTop - zActHoleBot) / 2.;
  auto actHoleCyl = new G4Tubs("HPGeActHole", 0., RhAct, hActHole, 0., twopi);
  G4double zActHoleC = (zActTop + zActHoleBot) / 2.;
  auto actSolid = new G4SubtractionSolid("HPGe_ActiveSolid", actOuterCyl, actHoleCyl, nullptr, G4ThreeVector(0, 0, zActHoleC - zActC));
  auto actLV = new G4LogicalVolume(actSolid, matGe, "HPGe_Active_LV");
  new G4PVPlacement(nullptr, G4ThreeVector(0, 0, zActC), actLV, "HPGe_Active", crysLV, false, 0, fCheckOverlaps);

  //
  // print parameters
  //
  G4cout
    << G4endl
    << "------------------------------------------------------------" << G4endl
    << "---> [Description]" << G4endl
    << "------------------------------------------------------------" << G4endl;

  //
  // Visualization attributes
  //
  // worldLV->SetVisAttributes(G4VisAttributes::GetInvisible());
  // Set the forced wireframe style
  G4VisAttributes* wireframeAttrib = new G4VisAttributes(G4Colour::White());
  wireframeAttrib->SetForceWireframe(true);
  worldLV->SetVisAttributes(wireframeAttrib);
  auto visCap = new G4VisAttributes(G4Colour(0.7, 0.7, 0.7)); visCap->SetForceSolid(false); capLV->SetVisAttributes(visCap);
  auto visCav = new G4VisAttributes(G4Colour(0.9, 0.9, 1.0, 0.1)); visCav->SetForceWireframe(true); cavLV->SetVisAttributes(visCav);
  auto visWell = new G4VisAttributes(G4Colour(0.95, 0.95, 1.0, 0.2)); wellVacLV->SetVisAttributes(visWell);
  auto visGe = new G4VisAttributes(G4Colour(0.3, 0.3, 0.8)); crysLV->SetVisAttributes(visGe);
  auto vis_t6 = new G4VisAttributes(G4Colour(0.0, 0.8, 0.0)); vis_t6->SetForceSolid(false); t6_LV->SetVisAttributes(vis_t6);
  if (auto t7_LV = G4LogicalVolumeStore::GetInstance()->GetVolume("HPGe_t7_Dead_LV")) {
      auto vis_t7 = new G4VisAttributes(G4Colour(1.0, 0.0, 0.0)); vis_t7->SetForceSolid(false); t7_LV->SetVisAttributes(vis_t7);
  }
  auto visAct = new G4VisAttributes(G4Colour(0.8, 0.0, 0.8)); visAct->SetForceSolid(true); actLV->SetVisAttributes(visAct);

  //
  // Always return the physical World
  //
  return worldPV;
}

void DetectorConstruction::ConstructSDandField()
{
  auto sdManager = G4SDManager::GetSDMpointer();

  auto detectorSD = new ActiveDetectorSD("GeSD");
  sdManager->AddNewDetector(detectorSD);

  // Attach SD to the germanium well
  G4LogicalVolume* ActiveDetectorLV = G4LogicalVolumeStore::GetInstance()->GetVolume("HPGe_Active_LV");
  if (ActiveDetectorLV) {
    SetSensitiveDetector(ActiveDetectorLV, detectorSD);
  }
}

}