void bbr8()
{
TFile *f = TFile::Open("Higgs_background.root");
TTree *t = (TTree*)f->Get("Events");
TH1F *h = new TH1F("h", "Electron_eta_1_Histogram", 35, -3,5);
float Electron_eta_1 = 0;
t->SetBranchAddress("Electron_eta_1", &Electron_eta_1);
Long64_t nEntries = t->GetEntries();
for(Long64_t i =0; i<nEntries; ++i){
	t->GetEntry(i);
	h->Fill(Electron_eta_1);
	}
TCanvas*c = new TCanvas("c", "Electron_eta_1_Histogram", 800,600);
h->Draw();
c->SaveAs("Electron_eta_1_Histogram.png");
delete h;
delete c;
f->Close();
}

