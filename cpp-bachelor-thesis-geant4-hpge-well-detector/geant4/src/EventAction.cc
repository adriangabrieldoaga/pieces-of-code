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
/// \file B4/B4a/src/EventAction.cc
/// \brief Implementation of the B4a::EventAction class

/*
Started from example B4a and made modifications.
*/

#include "EventAction.hh"
#include "RunAction.hh"

#include "G4AnalysisManager.hh"
#include "G4RunManager.hh"
#include "G4Event.hh"
#include "G4UnitsTable.hh"

#include "Randomize.hh"
#include <iomanip>

#include "G4SDManager.hh"
#include "G4HCofThisEvent.hh"
#include "ActiveDetectorHit.hh"

namespace B4a
{

void EventAction::BeginOfEventAction(const G4Event* /*event*/)
{

}

void EventAction::EndOfEventAction(const G4Event* event)
{
  // Print per event (modulo n)
  //
  auto eventID = event->GetEventID();
  auto printModulo = G4RunManager::GetRunManager()->GetPrintProgress();

  // Retrieve deposited energy from sensitive detector
  auto sdManager = G4SDManager::GetSDMpointer();
  G4int collectionID = sdManager->GetCollectionID("GeSD/DetectorHitsCollection");

  auto hce = event->GetHCofThisEvent();
  if (!hce) return;

  auto hitsCollection = static_cast<DetectorHitsCollection*>(hce->GetHC(collectionID));
  if (!hitsCollection) return;

  G4double edepInGe = (*hitsCollection)[0]->GetEdep();

    
  // Fill spectrum histogram (add this in RunAction.cc if not already created)
  // get analysis manager
  if(edepInGe > 0.0) {  //daca energia depusa e 0, nu adaugam la histograma nimic
    // G4cout<<edepInGe<<G4endl;
    auto analysisManager = G4AnalysisManager::Instance();
    analysisManager->FillH1(0, edepInGe);
  }
  
}

}