#include <iostream>
#include <string>
#include <stdlib.h>

#include "TFile.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TPaveText.h"
#include "TLegend.h"



TStyle* setStyle();


int main( int argc, char* argv[] ) {

  
  std::string runName = "test_10";
  if( argc>1 ) {
    std::string runName_str(argv[1]);
    runName = runName_str;
  }


  std::string fileName = "PosAn_" + runName + ".root";
  TFile* file = TFile::Open( fileName.c_str() );
  

  TStyle* style = setStyle();
  style->cd();


  TCanvas* c1 = new TCanvas("c1", "", 600, 600);
  c1->cd();

  TH2D* h2_xyPos = (TH2D*)file->Get("xyPos"); 
  TH2D* h2_xyPos_hodo = (TH2D*)file->Get("xyPos_hodo"); 

  TH2D* h2_axes = new TH2D("axes", "", 10, -10., 10., 10, -10., 10.);
  h2_axes->SetXTitle("X Position [mm]");
  h2_axes->SetYTitle("Y Position [mm]");

  h2_axes->Draw();

  h2_xyPos_hodo->Draw("same");

  h2_xyPos->SetMarkerColor(kRed);
  h2_xyPos->Draw("same");

  TPaveText* label_top = new TPaveText(0.4,0.953,0.975,0.975, "brNDC");
  label_top->SetFillColor(kWhite);
  label_top->SetTextSize(0.038);
  label_top->SetTextAlign(31); // align right
  label_top->SetTextFont(62);
  label_top->AddText("500 MeV Electron Beam");
  label_top->Draw("same");

  TPaveText* label_run = new TPaveText(0.34,0.86,0.54,0.91, "brNDC");
  label_run->SetFillColor(kWhite);
  label_run->SetTextSize(0.033);
  label_run->SetTextAlign(31); // align right
  label_run->SetTextFont(62);
  label_run->AddText(Form("Run %s", runName.c_str()));
  label_run->Draw("same");

  c1->SaveAs("xyPos.eps");
  c1->SaveAs("xyPos.png");

  return 0;

}


TStyle* setStyle() {

  // set the TStyle
  TStyle* style_ = new TStyle("DrawBaseStyle", "");
  style_->SetCanvasColor(0);
  style_->SetPadColor(0);
  style_->SetFrameFillColor(0);
  style_->SetStatColor(0);
  style_->SetOptStat(0);
  style_->SetTitleFillColor(0);
  style_->SetCanvasBorderMode(0);
  style_->SetPadBorderMode(0);
  style_->SetFrameBorderMode(0);
  style_->SetPadBottomMargin(0.12);
  style_->SetPadLeftMargin(0.12);
  style_->cd();

  // For the canvas:
  style_->SetCanvasBorderMode(0);
  style_->SetCanvasColor(kWhite);
  style_->SetCanvasDefH(600); //Height of canvas
  style_->SetCanvasDefW(600); //Width of canvas
  style_->SetCanvasDefX(0); //POsition on screen
  style_->SetCanvasDefY(0);

  // For the Pad:
  style_->SetPadBorderMode(0);
  style_->SetPadColor(kWhite);
  style_->SetPadGridX(false);
  style_->SetPadGridY(false);
  style_->SetGridColor(0);
  style_->SetGridStyle(3);
  style_->SetGridWidth(1);

  // For the frame:
  style_->SetFrameBorderMode(0);
  style_->SetFrameBorderSize(1);
  style_->SetFrameFillColor(0);
  style_->SetFrameFillStyle(0);
  style_->SetFrameLineColor(1);
  style_->SetFrameLineStyle(1);
  style_->SetFrameLineWidth(1);


  // Margins:
  style_->SetPadTopMargin(0.05);
  style_->SetPadBottomMargin(0.15);//0.13);
  style_->SetPadLeftMargin(0.15);//0.16);
  style_->SetPadRightMargin(0.05);//0.02);

  // For the Global title:

  style_->SetOptTitle(0);
  style_->SetTitleFont(42);
  style_->SetTitleColor(1);
  style_->SetTitleTextColor(1);
  style_->SetTitleFillColor(10);
  style_->SetTitleFontSize(0.05);

  // For the axis titles:

  style_->SetTitleColor(1, "XYZ");
  style_->SetTitleFont(42, "XYZ");
  style_->SetTitleSize(0.05, "XYZ");
  style_->SetTitleXOffset(1.15);//0.9);
  style_->SetTitleYOffset(1.4); // => 1.15 if exponents

  // For the axis labels:

  style_->SetLabelColor(1, "XYZ");
  style_->SetLabelFont(42, "XYZ");
  style_->SetLabelOffset(0.007, "XYZ");
  style_->SetLabelSize(0.045, "XYZ");

  // For the axis:

  style_->SetAxisColor(1, "XYZ");
  style_->SetStripDecimals(kTRUE);
  style_->SetTickLength(0.03, "XYZ");
  style_->SetNdivisions(510, "XYZ");
  style_->SetPadTickX(1); // To get tick marks on the opposite side of the frame
  style_->SetPadTickY(1);

  style_->cd();

  return style_;

}


