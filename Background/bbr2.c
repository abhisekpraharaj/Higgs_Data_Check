void bbr2()
{
TFile *f = TFile::Open("Higgs_background.root");
TTree *t = (TTree*)f->Get("Events");
TH1F *h = new TH1F("h", "Electron_pt_1_histogram", 30,0,294.5);
float Electron_pt_1 = 0;
t->SetBranchAddress("Electron_pt_1", &Electron_pt_1);
Long64_t nEntries = t->GetEntries();
for(Long64_t i=0; i<nEntries; ++i){
	t->GetEntry(i);
	h->Fill(Electron_pt_1);
	}
TCanvas *canvas = new TCanvas("canvas", "Electron_pt_1_histogram", 800, 600);
h->Draw();
canvas->SaveAs("Electron_pt_1_histogram.png");
delete h;
delete canvas;
f->Close();
}
