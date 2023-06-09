void r2()
{
    TFile *sf = TFile::Open("Higgs_signal.root");
    TFile *bf = TFile::Open("Higgs_background.root");

    TTree *st = static_cast<TTree*>(sf->Get("Events"));
    TTree *bt = static_cast<TTree*>(bf->Get("Events"));

    TH1F *sh = new TH1F("sh", "Electron_pt_1_signal_histogram", 39, 0, 296.9);
    TH1F *bh = new TH1F("bh", "Electron_pt_1_background_histogram", 39, 0, 296.9);

    st->Draw("Electron_pt_1>>sh");
    bt->Draw("Electron_pt_1>>bh");

    TCanvas *c = new TCanvas("c", "branch_2_Histogram");
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
    
    c->SaveAs("br_2.png");

    sf->Close();
    bf->Close();
}

