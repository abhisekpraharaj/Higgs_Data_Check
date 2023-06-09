void bbr7()
{
TFile *f = TFile::Open("Higgs_background.root");
TTree *t = (TTree*)f->Get("Events");
TH1F *h = new TH1F("h", "dPhim2e2_Histogram", 35, -3,5);
float dPhim2e2 = 0;
t->SetBranchAddress("dPhim2e2", &dPhim2e2);
Long64_t nEntries = t->GetEntries();
for(Long64_t i =0; i<nEntries; ++i){
	t->GetEntry(i);
	h->Fill(dPhim2e2);
	}
TCanvas*c = new TCanvas("c", "dPhim2e2_Histogram", 800,600);
h->Draw();
c->SaveAs("dPhim2e2_Histogram.png");
delete h;
delete c;
f->Close();
}

