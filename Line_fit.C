

void LinFit(const char *filename){
	bool file_exists;
	//Returnse false if the file was located:
	file_exists = gSystem->AccessPathName(filename);
	
	//exits the program if the file was not found
	if(file_exists == false){
	std::cout << "File located." << std::endl;
	}
	else{
	std::cout << "File not found." << std::endl;
	return;
	};
	
	TCanvas *c1 = new TCanvas("c1", "hat", 200, 10, 700, 500);
	TPad *pad1 = new TPad("pad1", "plot", 0, 0.33, 1, 1);
	pad1->SetGrid();
	pad1->Draw();
	
	TPad *pad2 = new TPad("pad2", "Residuals", 0, 0, 1, 0.33);
	pad2->SetGrid();
	pad2->Draw();
	
	pad1->cd();
	TGraphErrors *gr = new TGraphErrors(filename);
	gr->SetTitle("TGraphErrors Example");
	gr->SetMarkerColor(4);
	gr->SetMarkerStyle(21);
	gr->Draw("AP");
	gr->Fit("pol1", "F");
	
	pad2->cd();
	TF1 *g = (TF1*) gr->GetListOfFunctions()->FindObject("pol1");
	double c = g->GetParameter(0);
	double m = g->GetParameter(1);
	TF1 *f = new TF1("lin", "pol1");
	f->FixParameter(0, c);
	f->FixParameter(1,m);
	
	int n_data = gr->GetN();

	
	TGraphErrors *res = new TGraphErrors();
	for (int  i = 0; i < n_data; i++){
		double y_res = gr->GetPointY(i) - f->Eval(gr->GetPointX(i));
		
		res->SetPoint(i, gr->GetPointX(i), y_res);
	} 
	res->SetMarkerColor(4);
	res->SetMarkerStyle(21);
	
	res->Draw("AP");

}




