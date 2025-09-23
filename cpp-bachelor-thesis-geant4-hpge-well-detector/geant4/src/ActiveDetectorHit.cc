/*
Started from example B4a and made modifications.
*/

#include "ActiveDetectorHit.hh"

G4ThreadLocal G4Allocator<ActiveDetectorHit>* DetectorHitAllocator = nullptr;

ActiveDetectorHit::ActiveDetectorHit() = default;
ActiveDetectorHit::~ActiveDetectorHit() = default;

ActiveDetectorHit::ActiveDetectorHit(const ActiveDetectorHit& right)
    : G4VHit(), fEdep(right.fEdep) {}

const ActiveDetectorHit& ActiveDetectorHit::operator=(const ActiveDetectorHit& right)
{
    if (this != &right) {
        fEdep = right.fEdep;
    }
    return *this;
}

G4bool ActiveDetectorHit::operator==(const ActiveDetectorHit& right) const
{
    return (this == &right);
}

void ActiveDetectorHit::AddEdep(G4double edep)
{
    fEdep += edep;
}

G4double ActiveDetectorHit::GetEdep() const
{
    return fEdep;
}