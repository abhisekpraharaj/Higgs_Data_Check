void bbr0()
{
TFile *f = TFile::Open("Higgs_background.root");
TTree *t = (TTree*)f->Get("Events");
TH1F *h = new TH1F("h", "Muon_pt_1_histogram", 39,0,276.9);
float Muon_pt_1 =0;
t->SetBranchAddress("Muon_pt_1", &Muon_pt_1);
Long64_t nEntries =t->GetEntries();
for(Long64_t i=0; i< nEntries; ++i){
	t->GetEntry(i);
	h->Fill(Muon_pt_1); 
}

TCanvas * c= new TCanvas("canvas", "Muon_pt_1_histogram", 800,600);
h->Draw();
c->SaveAs("Muon_pt_1_histogram.png");
delete h;
delete c;

f->Close();
}
