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
/// \file B4/B4a/src/SteppingAction.cc
/// \brief Implementation of the B4a::SteppingAction class

/*
Started from example B4a and made modifications.
*/

#include "SteppingAction.hh"
#include "EventAction.hh"
#include "DetectorConstruction.hh"

#include "G4Step.hh"
#include "G4RunManager.hh"

#include "G4TransportationManager.hh"
#include <fstream>
#include "G4SystemOfUnits.hh"

using namespace B4;

namespace B4a
{

SteppingAction::SteppingAction(const DetectorConstruction* detConstruction,
                               EventAction* eventAction)
  : fDetConstruction(detConstruction),
    fEventAction(eventAction)
{}

/*
void writeMaterialAtOrigin()
{
    G4ThreeVector point(0., 0., (A/2));
    auto navigator = G4TransportationManager::GetTransportationManager()->GetNavigatorForTracking();
    auto volume = navigator->LocateGlobalPointAndSetup(point, nullptr, false);

    std::ofstream outfile("C:\\geant4-run-examples\\material_at_origin.txt");
    if (volume)
    {
        auto material = volume->GetLogicalVolume()->GetMaterial();
        outfile << "Material at (0., 0., (A/2) * mm) is: " << material->GetName() << std::endl;
    }
    else
    {
        outfile << "No volume found at (0., 0., (A/2) * mm)" << std::endl;
    }
    outfile.close();
}
*/

void SteppingAction::UserSteppingAction(const G4Step* step)
{
    /*
    static bool called = false;
    if (!called)
    {
        writeMaterialAtOrigin();
        called = true;
    }
    */
}

}