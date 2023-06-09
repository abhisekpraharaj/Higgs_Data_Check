void r7()
{
    TFile *sf = TFile::Open("Higgs_signal.root");
    TFile *bf = TFile::Open("Higgs_background.root");

    TTree *st = static_cast<TTree*>(sf->Get("Events"));
    TTree *bt = static_cast<TTree*>(bf->Get("Events"));

    TH1F *sh = new TH1F("sh", "dPhim2e2_signal_histogram", 39, -3, 5);
    TH1F *bh = new TH1F("bh", "dPhim2e2_background_histogram", 39, -3, 5);

    st->Draw("dPhim2e2>>sh");
    bt->Draw("dPhim2e2>>bh");

    TCanvas *c = new TCanvas("c", "branch_0_Histogram");
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
    
    c->SaveAs("br_7.png");

    sf->Close();
    bf->Close();
}

