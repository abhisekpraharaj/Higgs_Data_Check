void br13()
{
    // Open the ROOT file
    TFile *file = TFile::Open("Higgs_signal.root");
    // Check if the file is open
    if (!file || file->IsZombie()) {
        std::cout << "Error opening the ROOT file." << std::endl;
        return;
    }
    // Get the "Events" tree from the file
    TTree *t1 = (TTree*)file->Get("Events");
    TH1F* histogram = new TH1F("histogram", "dPhie1e2_Histogram", 39, 0,276.9);
    // Create a variable to hold the branch data
    float Muon_pt_2 = 0.0;
    // Set the branch address to the variable
    t1->SetBranchAddress("Muon_pt_2", &Muon_pt_2);
    // Get the number of entries in the tree
    Long64_t numEntries = t1->GetEntries();
    // Loop over the tree entries
    for (Long64_t i = 0; i < numEntries; ++i) {
        // Get the i-th entry
        t1->GetEntry(i);
        // Fill the histogram with the branch data
        histogram->Fill(Muon_pt_2);
    }
    // Create a canvas to display the histogram
    TCanvas *canvas = new TCanvas("canvas", "Muon_pt_2Histogram", 800, 600);
    // Draw the histogram on the canvas
    histogram->Draw();
    // Print the maximum bin content
    std::cout << "Maximum bin content: " << histogram->GetMaximum() << std::endl;
    // Save the canvas as an image file
    canvas->SaveAs("histogram_Muon_pt_2.png");
    // Clean up memory
    delete histogram;
    delete canvas;
    // Close the file
    file->Close();
}

