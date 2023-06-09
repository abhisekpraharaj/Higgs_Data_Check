void bbr1()
{
TFile *f = TFile::Open("Higgs_background.root");
TTree *t = (TTree*)f->Get("Events");
TH1F *h = new TH1F("h", "Muon_pt_2_histogram", 30,0,294.5);
float Muon_pt_2 = 0;
t->SetBranchAddress("Muon_pt_2", &Muon_pt_2);
Long64_t nEntries = t->GetEntries();
for(Long64_t i=0; i<nEntries; ++i){
	t->GetEntry(i);
	h->Fill(Muon_pt_2);
	}
TCanvas *canvas = new TCanvas("canvas", "Muon_pt_2_histogram", 800, 600);
h->Draw();
canvas->SaveAs("Muon_pt_2_histogram.png");
delete h;
delete canvas;
f->Close();
}
