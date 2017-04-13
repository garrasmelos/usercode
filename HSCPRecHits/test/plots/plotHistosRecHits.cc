#include "plotHistosRecHits.h"


int plotHistosRecHits()
{
	setStyleTemplate();
   writeExtraText = true;       // if extra text
  	extraText  = "Preliminary";  // default extra text is "Preliminary"
  	lumi_13TeV = "2.7 fb^{-1}";
  	lumi_8TeV  = "19.1 fb^{-1}"; // default is "19.7 fb^{-1}"
  	lumi_7TeV  = "4.9 fb^{-1}";  // default is "5.1 fb^{-1}"
  	lumi_13TeV_MC = "MC Pythia6 - #tilde{#tau} of GMSB model" ;
  	
  	int iPeriod = 100;    // 1=7TeV, 2=8TeV, 3=7+8TeV, 4=13TeV, 7=7+8+13TeV 
  	int iPos    = 11;
	TString infile = "m1599_Gate1_BX_ToF_RecHits_test.root";
   TFile* fin = new TFile(infile);
   TCanvas * c1 = new TCanvas("c1", "c1", 1000, 1000);
   TH1D *fHBeta_pas = (TH1D*)fin->Get("demo2/fHbeta_pas");
   TH1D *fHBeta_tot = (TH1D*)fin->Get("demo2/fHbeta_tot");
   TH1D *fHBeta_resolution = (TH1D*)fin->Get("demo2/fHres");
   TEfficiency* trigEff = new TEfficiency(*fHBeta_pas,*fHBeta_tot);
   trigEff->SetTitle(";#beta_{GEN};Efficiency");
   trigEff->SetMarkerColor(kRed+2);
   trigEff->SetLineColor(kRed+2);
   trigEff->SetName("trigEff");
   trigEff->Draw();
   TLegend *legend = new TLegend(0.4,0.25,0.65,0.32);
   legend->AddEntry(trigEff,"HSCP trigger","lep");
   legend->SetTextSize(0.025);
   //legend->SetTextColor();
   legend->SetLineColor(1);
   legend->SetBorderSize(0);
   legend->Draw();
   CMS_lumi( c1, iPeriod, iPos );
   c1->SaveAs("trigEff-HSCPtrigger.pdf");
   
   c1->cd();
	fHBeta_resolution->SaveAs("beta_GenRes.root");
	fHBeta_resolution->GetXaxis()->SetTitle("#beta resolution (#beta_{GEN}-#beta_{RPC})/#beta_{GEN}");
	fHBeta_resolution->SetLineColor(kGreen+2);
	fHBeta_resolution->SetFillStyle(3444);
	fHBeta_resolution->SetFillColor(kGreen+2);
	
	
	fHBeta_resolution->Draw();
	
	CMS_lumi( c1, iPeriod, iPos );
	c1->SaveAs("beta_GenRes.pdf");
/*
	fHBetaSel->Draw();
	fHBetaSel->SaveAs("histograms/"+infile+"_BetaSel.root");
	fHBetaSel->GetXaxis()->SetTitle("#beta(sTau)");
	c1->SaveAs("images/"+infile+"_BetaSel.pdf");
	
	c1->cd();
	gPad->SetRightMargin(0.05);
	gPad->SetLeftMargin(0.15);
	
	eff->SetTitle(";#beta;Efficiency");
	eff->Draw();
	eff->SaveAs("histograms/"+infile+"_eff.root");
	c1->SaveAs("images/"+infile+"_eff.pdf");
	
	
	
	
*/	
	return 0;
}
