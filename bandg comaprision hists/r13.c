void r13()
{
    TFile *sf = TFile::Open("Higgs_signal.root");
    TFile *bf = TFile::Open("Higgs_background.root");

    TTree *st = static_cast<TTree*>(sf->Get("Events"));
    TTree *bt = static_cast<TTree*>(bf->Get("Events"));

    TH1F *sh = new TH1F("sh", "dPhie1e2_signal_histogram", 35 ,-6 ,5);
    TH1F *bh = new TH1F("bh", "dPhie1e2_background_histogram", 35 ,6 ,5);

    st->Draw("dPhie1e2>>sh");
    bt->Draw("dPhie1e2>>bh");

    TCanvas *c = new TCanvas("c", "branch_13_Histogram");
    bh->Draw();
    sh->Draw("same");
    
    
    bh->SetLineColor(kRed);
    bh->SetFillColor(kRed);
    bh->SetFillStyle(3001);
    
	
    TLegend* legend = new TLegend(0.6, 0.6, 0.9, 0.9);
    legend->AddEntry(bh, "Background", "f");
    legend->AddEntry(sh, "Signal", "l");
    legend->Draw();


    c->Update();
    c->Modified();
    c->Draw();
    gSystem->ProcessEvents();
    
    c->SaveAs("br_13.png");

    sf->Close();
    bf->Close();
}

