

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
	c1-> SetGrid();
	
	TGraphErrors *gr = new TGraphErrors(filename);
	gr->SetTitle("TGraphErrors Example");
	gr->SetMarkerColor(4);
	gr->SetMarkerStyle(21);
	gr->Draw("AP");
	
	gr->Fit("pol1", "F");

	//gr->Draw("c1");
}


