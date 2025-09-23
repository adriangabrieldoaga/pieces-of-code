	Credit for creating the Geant4 toolkit and ROOT framework goes to the international collaborations of physicists and software developers at CERN and associated institutes.
	I kept the Geant4 copyright notices in the files.
	Started from example B4a and made modifications.

High-Purity Germanium (HPGe) Well Detector
	Simulation and data analysis of a radiation detector’s response at multiple radioactive source positions using C++, Geant4 and ROOT as part of bachelor’s degree thesis.

	The project addresses the following aspects:
- Generation of isotropic emission by a point source of photons
- Geometric configuration of an HPGe well detector
- Simulating the detector response using Geant4
- Recording and analyzing the energy spectrum with ROOT
- Determination of photopeak efficiencies of the detector
- Construction of the photopeak efficiency curve based on simulated gamma photons of various energies
 
	The simulated energies are the photopeak energies of europium-152 and cobalt-60.
Eu-152 photopeak energies: 122, 245, 344, 441, 444, 779, 867, 964, 1086, 1090, 1112, 1213, 1299, 1408 keV
Co-60 photopeak energies: 1173, 1333 keV
	One million photons were simulated for every energy.

	There are two types of visualization, namely Wireframe visualization and Solid visualization. We can make some volumes always be viewed in only one of the types. Wireframe view helps to observe the interior without being blocked by solid walls. It reveals the arrangement of functionality and content through simple lines and shapes, without detailed graphics.

Source for the files mentioned below: AMETEK-ORTEC, https://www.ortec-online.com/-/media/ametekortec/brochures/g/gwl.pdf?la=en&revision=88130e33-359e-443d-8464-fa4b1e0ce99a
ametek-ortec-dimensions.txt
ametek-ortec-dimensions-scheme.png
ametek-ortec-hpge-well-detector-simplified-isometric-view.png