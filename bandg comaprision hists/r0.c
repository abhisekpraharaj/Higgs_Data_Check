void r0()
{
    TFile *sf = TFile::Open("Higgs_signal.root");
    TFile *bf = TFile::Open("Higgs_background.root");

    TTree *st = static_cast<TTree*>(sf->Get("Events"));
    TTree *bt = static_cast<TTree*>(bf->Get("Events"));

    TH1F *sh = new TH1F("sh", "Muon_pt_1_signal_histogram", 39, 0, 296.9);
    TH1F *bh = new TH1F("bh", "Muon_pt_1_background_histogram", 39, 0, 296.9);

    st->Draw("Muon_pt_1>>sh");
    bt->Draw("Muon_pt_1>>bh");

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
    
    c->SaveAs("br_0.png");

    sf->Close();
    bf->Close();
}

