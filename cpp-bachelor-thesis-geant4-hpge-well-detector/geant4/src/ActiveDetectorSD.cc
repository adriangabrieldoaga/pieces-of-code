/*
Started from example B4a and made modifications.
*/

#include "ActiveDetectorSD.hh"
#include "G4HCofThisEvent.hh"
#include "G4Step.hh"
#include "G4SDManager.hh"
#include "G4TouchableHistory.hh"

ActiveDetectorSD::ActiveDetectorSD(const G4String& name)
    : G4VSensitiveDetector(name)
{
    collectionName.insert("DetectorHitsCollection");
}

void ActiveDetectorSD::Initialize(G4HCofThisEvent* hce)
{
    fHitsCollection = new DetectorHitsCollection(SensitiveDetectorName, collectionName[0]);
    if (fHitsCollectionID < 0) {
        fHitsCollectionID = G4SDManager::GetSDMpointer()->GetCollectionID(fHitsCollection);
    }
    hce->AddHitsCollection(fHitsCollectionID, fHitsCollection);

    // One hit per event
    auto hit = new ActiveDetectorHit();
    fHitsCollection->insert(hit);
}

G4bool ActiveDetectorSD::ProcessHits(G4Step* step, G4TouchableHistory*)
{
    G4double edep = step->GetTotalEnergyDeposit();
    if (edep <= 0.) return false;

    if(edep>0){ 
         (*fHitsCollection)[0]->AddEdep(edep);   //adaugam doar hiturile cu energia mai mare de 0
        //  G4cout << "Hit: " << edep << G4endl;
    }
    return true;
}

void ActiveDetectorSD::EndOfEvent(G4HCofThisEvent*) {}