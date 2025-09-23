#include <vector>
#include <string>
#include <iostream>
#include "TFile.h"
#include "TH1D.h"

using namespace std;

double getEfficiency(double energy, double nrGamma) {
    // Placeholder for actual efficiency calculation
    cout<<energy<<"  "<<nrGamma<<endl;

    string filename = "B4_" + std::to_string((int)energy) + ".root";
    TFile* f=new TFile(filename.c_str(),"read");
    f->cd();
    TH1D* h1 = (TH1D*)gDirectory->Get("PhotonSpectrum");
    double counts = h1->Integral(energy-3, energy+3);

    return counts / nrGamma;
}

double plotEffCurve(const vector<double>& energies, const vector<double>& efficiencies) {
    // Placeholder for actual plotting code
    for (size_t i = 0; i < energies.size(); ++i) {
        cout << "Energy: " << energies[i] << ", Efficiency: " << efficiencies[i] << endl;
    }

    TCanvas* canvas = new TCanvas("canvas", "Efficiency Curve", 800, 600);
    // Create a graph
    TGraph* graph = new TGraph(energies.size(), energies.data(), efficiencies.data());
    graph->SetTitle("Efficiency Curve;Energy (MeV);Efficiency");
    graph->Draw("AL*"); 
    return 0;
}

int build_eff_curve() {

    vector<double> energies = {122, 245, 344, 441, 444, 779, 867, 964, 1086, 1090, 1112, 1173, 1213, 1299, 1333, 1408};
    vector<double> nrGammas = {1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000 };
    vector<double>efficiencies;
    for (const auto& energy : energies) {
        // Call the exampleB4a.exe with the current energy value
        std::string command = "B4_" + std::to_string((int)energy) + ".root";
        cout<< command.c_str()<<endl;
        double efficiency = getEfficiency(energy, nrGammas[&energy - &energies[0]]);
        efficiencies.push_back(efficiency);
       
    }

    plotEffCurve(energies, efficiencies);

    return 0;
}