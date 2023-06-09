void sgread()
{
TFile * f1 = new TFile ("Higgs_signal.root", "READ");
TTree *t1 = (TTree*)f1->Get("Events");
t1->Print();
f1->Close();
}
