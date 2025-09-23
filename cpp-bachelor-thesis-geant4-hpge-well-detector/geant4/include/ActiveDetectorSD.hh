/*
Started from example B4a and made modifications.
*/

#ifndef B4aActiveDetectorSD_h
#define B4aActiveDetectorSD_h 1

#include "G4VSensitiveDetector.hh"
#include "ActiveDetectorHit.hh"

class ActiveDetectorSD : public G4VSensitiveDetector
{
public:
	ActiveDetectorSD(const G4String& name);
	~ActiveDetectorSD() override = default;

	void Initialize(G4HCofThisEvent* hce) override;
	G4bool ProcessHits(G4Step* step, G4TouchableHistory*) override;
	void EndOfEvent(G4HCofThisEvent* hce) override;

private:
	DetectorHitsCollection* fHitsCollection = nullptr;
	G4int fHitsCollectionID = -1;
};

#endif