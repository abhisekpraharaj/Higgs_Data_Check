void bbr4()
{
TFile *f = TFile::Open("Higgs_background.root");
TTree *t = (TTree*)f->Get("Events");
TH1F *h = new TH1F("h", "dPhim1e1_Histogram", 35, -3,5);
float dPhime1e1 = 0;
t->SetBranchAddress("dPhime1e1", &dPhime1e1);
Long64_t nEntries = t->GetEntries();
for(Long64_t i =0; i<nEntries; ++i){
	t->GetEntry(i);
	h->Fill(dPhime1e1);
	}
TCanvas*c = new TCanvas("c", "dPhime1e1_Histogram", 800,600);
h->Draw();
c->SaveAs("dPhime1e1_Histogram.png");
delete h;
delete c;
f->Close();
}

