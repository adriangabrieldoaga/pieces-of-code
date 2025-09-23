/*
Started from example B4a and made modifications.
*/

#ifndef B4aActiveDetectorHit_h
#define B4aActiveDetectorHit_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"

class ActiveDetectorHit : public G4VHit
{
public:
	ActiveDetectorHit();
	~ActiveDetectorHit() override;

	ActiveDetectorHit(const ActiveDetectorHit&);
	const ActiveDetectorHit& operator=(const ActiveDetectorHit&);
	G4bool operator==(const ActiveDetectorHit&) const;

	inline void* operator new(size_t);
	inline void operator delete(void*);

	void AddEdep(G4double edep);

	G4double GetEdep() const;

private:
	G4double fEdep = 0.;
};

using DetectorHitsCollection = G4THitsCollection<ActiveDetectorHit>;

extern G4ThreadLocal G4Allocator<ActiveDetectorHit>* DetectorHitAllocator;

inline void* ActiveDetectorHit::operator new(size_t)
{
	if (!DetectorHitAllocator) DetectorHitAllocator = new G4Allocator<ActiveDetectorHit>;
	return (void*)DetectorHitAllocator->MallocSingle();
}

inline void ActiveDetectorHit::operator delete(void* hit)
{
	DetectorHitAllocator->FreeSingle((ActiveDetectorHit*)hit);
}

#endif