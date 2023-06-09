void bbr11()
{
TFile *f = TFile::Open("Higgs_background.root");
TTree *t = (TTree*)f->Get("Events");
TH1F *h = new TH1F("h", "Muon_eta_2_Histogram", 35, -3,5);
float Muon_eta_2 = 0;
t->SetBranchAddress("Muon_eta_2", &Muon_eta_2);
Long64_t nEntries = t->GetEntries();
for(Long64_t i =0; i<nEntries; ++i){
	t->GetEntry(i);
	h->Fill(Muon_eta_2);
	}
TCanvas*c = new TCanvas("c", "Muon_eta_2_Histogram", 800,600);
h->Draw();
c->SaveAs("Muon_eta_2_Histogram.png");
delete h;
delete c;
f->Close();
}

