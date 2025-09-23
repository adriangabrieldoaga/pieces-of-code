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
/// \file B4/B4a/src/RunAction.cc
/// \brief Implementation of the B4::RunAction class

/*
Started from example B4a and made modifications.
*/

#include "RunAction.hh"

#include "G4AnalysisManager.hh"
#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

#include "GlobalVariables.hh"

namespace B4
{

RunAction::RunAction(G4double gammaEnergy)
  : gamma_energy(gammaEnergy)
{
  // set printing event number per each event
  G4RunManager::GetRunManager()->SetPrintProgress(1);

  // Create analysis manager
  // The choice of the output format is done via the specified
  // file extension.
  auto analysisManager = G4AnalysisManager::Instance();

  // Create directories
  // analysisManager->SetHistoDirectoryName("histograms");
  // analysisManager->SetNtupleDirectoryName("ntuple");
  analysisManager->SetVerboseLevel(1);

  // Creating histograms
  analysisManager->CreateH1("PhotonSpectrum", "Energy deposited in Ge well detector", numberOfBins, xMin, xMax); //aceasi histograma pentru toate energiile
}

void RunAction::BeginOfRunAction(const G4Run* /*run*/)
{
  // inform the runManager to save random number seed
  // G4RunManager::GetRunManager()->SetRandomNumberStore(true);

  // Get analysis manager
  auto analysisManager = G4AnalysisManager::Instance();

  // Open an output file
  //
  G4String fileName = "B4_" + std::to_string((int)gamma_energy) + ".root";
  analysisManager->OpenFile(fileName);
  // G4cout << "Using " << analysisManager->GetType() << G4endl;
}

void RunAction::EndOfRunAction(const G4Run* /*run*/)
{
  // print histogram statistics
  //

  //!!! analiza se face in root. In Geant doar salvam spectrul

  auto analysisManager = G4AnalysisManager::Instance();
  // if ( analysisManager->GetH1(1) ) {
  //   G4cout << G4endl << " ----> print histograms statistic ";
  //   if(isMaster) {
  //     G4cout << "for the entire run " << G4endl << G4endl;
  //   }
  //   else {
  //     G4cout << "for the local thread " << G4endl << G4endl;
  //   }
  // }

  // auto h1 = analysisManager->GetH1(0); // PhotonSpectrum
  // if (h1) {
  //     auto& axis = h1->axis();

  //     // Determine bin index for full photon energy
  //     G4int binIndex = -1;
  //     for (G4int i = 0; i < axis.bins(); ++i) {
  //         double low = axis.bin_lower_edge(i);
  //         double high = axis.bin_upper_edge(i);
  //         if (122. * keV >= low && 122. * keV < high) {
  //             binIndex = i;
  //             break;
  //         }
  //     }

  //     if (binIndex != -1) {
  //         G4int countPhotons = h1->bin_entries(binIndex);
  //         G4cout << "Number of photons depositing full 122 keV: "
  //             << countPhotons << G4endl;
  //     }
  //     else {
  //         G4cout << "122 keV is outside the histogram range!" << G4endl;
  //     }
  // }

  // // save histograms & ntuple
  //
  analysisManager->Write();
  analysisManager->CloseFile();
}

}