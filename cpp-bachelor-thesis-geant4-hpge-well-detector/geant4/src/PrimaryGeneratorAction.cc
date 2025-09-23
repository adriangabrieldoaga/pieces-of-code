﻿//
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
/// \file B4/B4a/src/PrimaryGeneratorAction.cc
/// \brief Implementation of the B4::PrimaryGeneratorAction class

/*
Started from example B4a and made modifications.
*/

#include "PrimaryGeneratorAction.hh"

#include "G4RunManager.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4PhysicalConstants.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"
// #include "G4RandomDirection.hh" // for G4RandomDirection()
#include "GlobalVariables.hh"

namespace B4
{

PrimaryGeneratorAction::PrimaryGeneratorAction(const B4::DetectorConstruction* detConstruction, G4double gammaEnergy)
  : fDetectorConstruction(detConstruction), fGammaEnergy(gammaEnergy)
{
  G4int nofParticles = 1;
  fParticleGun = new G4ParticleGun(nofParticles);
}

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
  delete fParticleGun;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
  // This function is called at the begining of event

  // In order to avoid dependence of PrimaryGeneratorAction
  // on DetectorConstruction class we get world volume
  // from G4LogicalVolumeStore
  //
  G4double worldZHalfLength = 0.;
  auto worldLV = G4LogicalVolumeStore::GetInstance()->GetVolume("World");

  // Check that the world volume has box shape
  // G4Box* worldBox = nullptr;
  // if (worldLV) {
  //   worldBox = dynamic_cast<G4Box*>(worldLV->GetSolid());
  // }

  // if (worldBox) {
  //   worldZHalfLength = worldBox->GetZHalfLength();
  // }
  // else  {
  //   G4ExceptionDescription msg;
  //   msg << "World volume of box shape not found." << G4endl;
  //   msg << "Perhaps you have changed geometry." << G4endl;
  //   msg << "The gun will be place in the center.";
  //   G4Exception("PrimaryGeneratorAction::GeneratePrimaries()",
  //     "MyCode0002", JustWarning, msg);
  // }

  auto particleDefinition
      = G4ParticleTable::GetParticleTable()->FindParticle("gamma");
  fParticleGun->SetParticleDefinition(particleDefinition);

  /*
  // Random direction from TestEm4
  // distribution uniform in solid angle
  G4double cosTheta = 2 * G4UniformRand() - 1., phi = twopi * G4UniformRand();
  G4double sinTheta = std::sqrt(1. - cosTheta * cosTheta);
  G4double ux = sinTheta * std::cos(phi),
      uy = sinTheta * std::sin(phi),
      uz = cosTheta;

  fParticleGun->SetParticleMomentumDirection(G4ThreeVector(ux, uy, uz));
  */

  // Random direction with theta = arccos(1 − 2 x RNDM) formula from documentation (Book For Application Developers Release 11.2., pg. 27 Biasing)
  G4double u = G4UniformRand();
  G4double theta = std::acos(1. - 2. * u);
  G4double phi = 2. * CLHEP::pi * G4UniformRand();

  G4double dirX = std::sin(theta) * std::cos(phi);
  G4double dirY = std::sin(theta) * std::sin(phi);
  G4double dirZ = std::cos(theta);

  fParticleGun->SetParticleMomentumDirection(G4ThreeVector(dirX, dirY, dirZ));

  // Random direction with G4RandomDirection() from G4RandomDirection.hh
  // fParticleGun->SetParticleMomentumDirection(G4ThreeVector(G4RandomDirection()));

  // Set particle energy
  fParticleGun->SetParticleEnergy(fGammaEnergy * keV); // Set energy in keV
  
  // Set gun position
  // fParticleGun->SetParticlePosition(G4ThreeVector(0., 0., +(global_zCapTopOuter + sourceDistance)));
  fParticleGun->SetParticlePosition(G4ThreeVector(0., 0., +(global_zWellVacBot + sourceDistance) ) );

  fParticleGun->GeneratePrimaryVertex(anEvent);
}

}