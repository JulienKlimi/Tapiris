#include <iostream>

#pragma once
#include<opencv2/core/core.hpp>													// allow the utilisation of the OpenCV library
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/opencv.hpp" 

#include<iostream>										
#include<conio.h>   



#include <math.h>
using namespace cv;																// namespace for the OpenCV functions
using namespace std;

// declaration of the various functions
Mat tailleImg(Mat imgDebut);
vector<Point2f> rectangle(Mat imgGrayscale);
Mat centreImg(vector<Point2f> pts_rect, Mat imgGrayscale);
vector<Point2f> harris(Mat imgGrayscale);
int triRatio(Mat im_out3);
int typeTri;	// 1 si tri par couleur, 0 si tri par forme
int couleur(Mat imgOriginal, Mat im_out3, vector<Point2f>  pts_rect);
string triCompare(Mat im_out3);

inline namespace TestFenetre {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  tri;
	private: System::Windows::Forms::ComboBox^  comboBoxTri;
	protected:


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::ComboBox^  comboBoxB1;
	private: System::Windows::Forms::ComboBox^  comboBoxB2;
	private: System::Windows::Forms::ComboBox^  comboBoxB3;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  lerreur;
	private: System::Windows::Forms::Label^  IndB1;
	private: System::Windows::Forms::Label^  IndB2;
	private: System::Windows::Forms::Label^  IndB3;
	private: System::Windows::Forms::Button^  restart;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label4;



	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tri = (gcnew System::Windows::Forms::Button());
			this->comboBoxTri = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->comboBoxB1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxB2 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxB3 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->lerreur = (gcnew System::Windows::Forms::Label());
			this->IndB1 = (gcnew System::Windows::Forms::Label());
			this->IndB2 = (gcnew System::Windows::Forms::Label());
			this->IndB3 = (gcnew System::Windows::Forms::Label());
			this->restart = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// tri
			// 
			this->tri->Location = System::Drawing::Point(38, 246);
			this->tri->Name = L"tri";
			this->tri->Size = System::Drawing::Size(122, 29);
			this->tri->TabIndex = 0;
			this->tri->Text = L"Lancer tri";
			this->tri->UseVisualStyleBackColor = true;
			this->tri->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// comboBoxTri
			// 
			this->comboBoxTri->AccessibleDescription = L"";
			this->comboBoxTri->AccessibleName = L"";
			this->comboBoxTri->Cursor = System::Windows::Forms::Cursors::Default;
			this->comboBoxTri->FormattingEnabled = true;
			this->comboBoxTri->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Tri par couleur", L"Tri par forme" });
			this->comboBoxTri->Location = System::Drawing::Point(38, 12);
			this->comboBoxTri->Name = L"comboBoxTri";
			this->comboBoxTri->Size = System::Drawing::Size(122, 21);
			this->comboBoxTri->TabIndex = 1;
			this->comboBoxTri->Text = L"Choix du tri";
			this->comboBoxTri->SelectedValueChanged += gcnew System::EventHandler(this, &MyForm::comboBoxTri_SelectedValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(35, 50);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Bac 1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(35, 99);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Bac 2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(35, 151);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Bac 3";
			// 
			// comboBoxB1
			// 
			this->comboBoxB1->FormattingEnabled = true;
			this->comboBoxB1->Location = System::Drawing::Point(87, 47);
			this->comboBoxB1->Name = L"comboBoxB1";
			this->comboBoxB1->Size = System::Drawing::Size(73, 21);
			this->comboBoxB1->TabIndex = 5;
			// 
			// comboBoxB2
			// 
			this->comboBoxB2->FormattingEnabled = true;
			this->comboBoxB2->Location = System::Drawing::Point(87, 96);
			this->comboBoxB2->Name = L"comboBoxB2";
			this->comboBoxB2->Size = System::Drawing::Size(73, 21);
			this->comboBoxB2->TabIndex = 6;
			// 
			// comboBoxB3
			// 
			this->comboBoxB3->FormattingEnabled = true;
			this->comboBoxB3->Location = System::Drawing::Point(87, 148);
			this->comboBoxB3->Name = L"comboBoxB3";
			this->comboBoxB3->Size = System::Drawing::Size(73, 21);
			this->comboBoxB3->TabIndex = 7;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(399, 246);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(62, 28);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Fermer";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// lerreur
			// 
			this->lerreur->AutoSize = true;
			this->lerreur->Location = System::Drawing::Point(35, 198);
			this->lerreur->Name = L"lerreur";
			this->lerreur->Size = System::Drawing::Size(0, 13);
			this->lerreur->TabIndex = 9;
			// 
			// IndB1
			// 
			this->IndB1->AutoSize = true;
			this->IndB1->Location = System::Drawing::Point(183, 49);
			this->IndB1->Name = L"IndB1";
			this->IndB1->Size = System::Drawing::Size(47, 13);
			this->IndB1->TabIndex = 10;
			this->IndB1->Text = L"0 pieces";
			// 
			// IndB2
			// 
			this->IndB2->AutoSize = true;
			this->IndB2->Location = System::Drawing::Point(183, 103);
			this->IndB2->Name = L"IndB2";
			this->IndB2->Size = System::Drawing::Size(47, 13);
			this->IndB2->TabIndex = 11;
			this->IndB2->Text = L"0 pieces";
			// 
			// IndB3
			// 
			this->IndB3->AutoSize = true;
			this->IndB3->Location = System::Drawing::Point(183, 152);
			this->IndB3->Name = L"IndB3";
			this->IndB3->Size = System::Drawing::Size(47, 13);
			this->IndB3->TabIndex = 12;
			this->IndB3->Text = L"0 pieces";
			// 
			// restart
			// 
			this->restart->Location = System::Drawing::Point(225, 246);
			this->restart->Name = L"restart";
			this->restart->Size = System::Drawing::Size(122, 28);
			this->restart->TabIndex = 13;
			this->restart->Text = L"Reprendre a zero";
			this->restart->UseVisualStyleBackColor = true;
			this->restart->Click += gcnew System::EventHandler(this, &MyForm::restart_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(268, 47);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(193, 122);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 14;
			this->pictureBox1->TabStop = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(265, 15);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 13);
			this->label4->TabIndex = 15;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(483, 287);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->restart);
			this->Controls->Add(this->IndB3);
			this->Controls->Add(this->IndB2);
			this->Controls->Add(this->IndB1);
			this->Controls->Add(this->lerreur);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBoxB3);
			this->Controls->Add(this->comboBoxB2);
			this->Controls->Add(this->comboBoxB1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBoxTri);
			this->Controls->Add(this->tri);
			this->Name = L"MyForm";
			this->Text = L"Fenêtre";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		//Compteurs pieces/bac
		int nbB1 = 0;
		int nbB2 = 0;
		int nbB3 = 0;

		//Action Boutton lancer tri
		private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			//Si un meme choix pour differents bacs
			if (comboBoxB1->SelectedIndex == comboBoxB2->SelectedIndex || comboBoxB1->SelectedIndex == comboBoxB3->SelectedIndex || comboBoxB3->SelectedIndex == comboBoxB2->SelectedIndex) {
				lerreur->Text = L"Erreur: meme type de piece dans differents bacs";
			}

			else {
				lerreur->Text = L"";

				//Homographie et affichage des images
				Mat imgOriginal;
				if (typeTri == 1) {
					int im = rand() % 3;

					if (im == 0) {
						imgOriginal = cv::imread("RondR.png");										// open the image we need to identify
					}
					if (im == 1) {
						imgOriginal = cv::imread("RondB.png");										// open the image we need to identify
					}
					if (im == 2) {
						imgOriginal = cv::imread("RondV.png");										// open the image we need to identify
					}
					if (imgOriginal.empty()) {													// verify image existence in the main repertory
						std::cout << "error: image not read from file\n\n";
						_getch();
					}
				}
				else {
					int im = rand() % 7;

					if (im == 0) {
						imgOriginal = cv::imread("Angle.png");										// open the image we need to identify
					}
					if (im == 1) {
						imgOriginal = cv::imread("Triangle.png");										// open the image we need to identify
					}
					if (im == 2) {
						imgOriginal = cv::imread("Fleche.png");										// open the image we need to identify
					}
					if (im == 3) {
						imgOriginal = cv::imread("Eclaire.png");										// open the image we need to identify
					}
					if (im == 4) {
						imgOriginal = cv::imread("Losange.png");										// open the image we need to identify
					}
					if (im == 5) {
						imgOriginal = cv::imread("Eclat.png");										// open the image we need to identify
					}
					if (im == 6) {
						imgOriginal = cv::imread("Etoile.png");										// open the image we need to identify
					}
					if (imgOriginal.empty()) {													// verify image existence in the main repertory
						std::cout << "error: image not read from file\n\n";
						_getch();
					}
				}
				Mat imgResize = tailleImg(imgOriginal);										// scaling to use size
				//namedWindow("image nouvelle taille", CV_WINDOW_AUTOSIZE);					// show result of the scaling, imgResize is the reference image
				//imshow("image nouvelle taille", imgResize);

				// different images on which we will work
				Mat imgGrayscale, imgBlurred, imgCanny, imgNB;

				cvtColor(imgResize, imgGrayscale, CV_BGR2GRAY);								// convert to grayscale

				GaussianBlur(imgGrayscale, imgBlurred, cv::Size(25, 25), 1.55);				// blur the image, last parameter is used to set the blur level												

				Canny(imgBlurred, imgCanny, 35, 60);										// detect the border of the image, the two last parameters are the lower and uper threshold)				

				threshold(imgBlurred, imgNB, 170, 255, CV_THRESH_BINARY);					// convert to black and white, the third parameter is the threshold, the Mat is still 8-bit (not 1)

																							// refocusing using the rectangle method
				vector<Point2f> pts_rect = rectangle(imgGrayscale);							// detection of the corners of the big rectanle, pts_rect will be used as parameters for homography, parameter must be grrayscaled image

				Mat im_out3 = centreImg(pts_rect, imgGrayscale);							// actual homography used to flatten and straigthen the image, parameter must be vector<Point2f> and the image you want to display
																							// refocusing using cornerHarris method								   

				//harris(imgNB);																// this whole part is not working for now, it is a big part of our researches and might be an implementation in the near future

				triRatio(im_out3);															// sorting using the ratio perimeter / area

				if (typeTri == 1) {															// Homography for both sorting algorithm
					Mat imgCH = tailleImg(imgOriginal);
					Mat couleurH = centreImg(pts_rect, imgCH);

					namedWindow("Homographie", CV_WINDOW_AUTOSIZE);
					imshow("Homographie", couleurH);
					int h = couleur(imgOriginal, im_out3, pts_rect);						// Color sorting
					label4->Text = L"Piece actuellement sur le tapis";
					if (h == 0) {
						pictureBox1->Image = Image::FromFile(L"RondR.png");
					}
					if (h == 1) {
						pictureBox1->Image = Image::FromFile(L"RondB.png");
					}
					if (h == 2) {
						pictureBox1->Image = Image::FromFile(L"RondV.png");
					}

					if (comboBoxB1->SelectedIndex == h) {									// Labels update
						nbB1 += 1;
						IndB1->Text = nbB1 + L" pieces";
					}
					else if (comboBoxB2->SelectedIndex == h) {
						nbB2 += 1;
						IndB2->Text = nbB2 +L" pieces";
					}
					else if (comboBoxB3->SelectedIndex == h) {
						nbB3 += 1;
						IndB3->Text = nbB3 + L" pieces";
					}


				}
				else {																		// Shape sorting
					int h;
					namedWindow("Homographie", CV_WINDOW_AUTOSIZE);
					imshow("Homographie", im_out3);
					string res = triCompare(im_out3);
					if (res == "EclaireP.png") {
						h = 0;
					}
					if (res == "EclatP.png") {
						h = 1;
					}
					if (res == "AngleP.png") {
						h = 2;
					}
					if (res == "FlecheP.png") {
						h = 3;
					}
					if (res == "LosangeP.png") {
						h = 4;
					}
					if (res == "TriangleP.png") {
						h = 5;
					}
					if (res == "EtoileP.png") {
						h = 6;
					}
					label4->Text = L"Piece actuellement sur le tapis";
					if (h == 0) {
						pictureBox1->Image = Image::FromFile(L"Eclaire.png");
					}
					if (h == 1) {
						pictureBox1->Image = Image::FromFile(L"Eclat.png");
					}
					if (h == 2) {
						pictureBox1->Image = Image::FromFile(L"Angle.png");
					}
					if (h == 3) {
						pictureBox1->Image = Image::FromFile(L"Fleche.png");
					}
					if (h == 4) {
						pictureBox1->Image = Image::FromFile(L"Losange.png");
					}
					if (h == 5) {
						pictureBox1->Image = Image::FromFile(L"Triangle.png");
					}
					if (h == 6) {
						pictureBox1->Image = Image::FromFile(L"Etoile.png");
					}
					if (comboBoxB1->SelectedIndex == h) {									// Labels update
						nbB1 += 1;
						IndB1->Text = nbB1 + L" pieces";
					}

					else if (comboBoxB2->SelectedIndex == h) {
						nbB2 += 1;
						IndB2->Text = nbB2 + L" pieces";
					}
					
					else if (comboBoxB3->SelectedIndex == h) {
						nbB3 += 1;
						IndB3->Text = nbB3 + L" pieces";
					}
					if (comboBoxB1->SelectedIndex == 7 && comboBoxB2->SelectedIndex != h && comboBoxB3->SelectedIndex != h) {
						nbB1 += 1;
						IndB1->Text = nbB1 + L" pieces";
					}
					if (comboBoxB2->SelectedIndex == 7 && comboBoxB1->SelectedIndex != h && comboBoxB3->SelectedIndex != h) {
						nbB2 += 1;
						IndB2->Text = nbB2 + L" pieces";
					}
					if (comboBoxB3->SelectedIndex == 7 && comboBoxB2->SelectedIndex != h && comboBoxB1->SelectedIndex != h) {
						nbB3 += 1;
						IndB3->Text = nbB3 + L" pieces";
					}
				}
																							//Homography's end


			}
		}

		//Action Boutton exit
		private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
			Application::Exit();
		}

		//Modification des combobox en fonction du choix du tri
		private: System::Void comboBoxTri_SelectedValueChanged(System::Object^  sender, System::EventArgs^  e) {
			nbB3 = 0;																		//Resets labels
			nbB2 = 0;
			nbB1 = 0;
			IndB3->Text = L"0 pieces";
			IndB2->Text = L"0 pieces";
			IndB1->Text = L"0 pieces";
			label4->Text = L" ";
			if (pictureBox1->Image != nullptr) {
				delete pictureBox1->Image;
				pictureBox1->Image = nullptr;
			}
			destroyWindow("Homographie");
			if (comboBoxTri->SelectedIndex == 0) {											//If color sorting is choosen
				typeTri = 1;
				if (comboBoxB1->Items->Count != 0) {										//If conboboxes contain values,
					for (int i = 0; i < 9; i++) {											//Browses comboboxes,
						this->comboBoxB1->Items->RemoveAt(0);								//And deletes components
						this->comboBoxB2->Items->RemoveAt(0);
						this->comboBoxB3->Items->RemoveAt(0);
					}
				}
					this->comboBoxB1->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Rouge", L"Bleu", L"Vert", L"Rien" });	//Adding component in comboboxes
					this->comboBoxB2->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Rouge", L"Bleu", L"Vert", L"Rien" });
					this->comboBoxB3->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Rouge", L"Bleu", L"Vert", L"Rien" });
			}
	
			else {																			//If shape sorting is choosen
				typeTri = 0;
				if (comboBoxB1->Items->Count != 0) {										//If conboboxes contain values,
					for (int i = 0; i < 4; i++) {											//Browses comboboxes,
						this->comboBoxB1->Items->RemoveAt(0);								//And deletes components
						this->comboBoxB2->Items->RemoveAt(0);
						this->comboBoxB3->Items->RemoveAt(0);
					}
				}
				this->comboBoxB1->Items->AddRange(gcnew cli::array< System::Object^  >(9) {L"Eclair",L"Eclat",L"Angle", L"Fleche", L"Losange", L"Triangle",L"Etoile",L"Le reste", L"Rien" });	//Adding component in comboboxes
				this->comboBoxB2->Items->AddRange(gcnew cli::array< System::Object^  >(9) {L"Eclair",L"Eclat",L"Angle", L"Fleche", L"Losange", L"Triangle",L"Etoile",L"Le reste", L"Rien" });
				this->comboBoxB3->Items->AddRange(gcnew cli::array< System::Object^  >(9) {L"Eclaire", L"Eclat", L"Angle", L"Fleche", L"Losange", L"Triangle", L"Etoile",L"Le reste", L"Rien" });
			}
		}
	private: System::Void restart_Click(System::Object^  sender, System::EventArgs^  e) {
		nbB3 = 0;													//Resets labels
		nbB2 = 0;
		nbB1 = 0;
		IndB3->Text = L"0 pieces";
		IndB2->Text = L"0 pieces";
		IndB1->Text = L"0 pieces";
		label4->Text = L" ";
		if (pictureBox1->Image != nullptr) {
			delete pictureBox1->Image;
			pictureBox1->Image = nullptr;
		}
		destroyWindow("Homographie");
	}
};
}
Mat tailleImg(Mat imgDebut)														// scaling of the source image
{
	vector<Point2f> pts_oui;													// these coordinates correspond to the area where the pieces when the picturre is taken (might modify)
	Point2f pp1(588, 1);
	Point2f pp2(1667, 1);
	Point2f pp3(1667, 1080);
	Point2f pp4(588, 1080);
	pts_oui.push_back(pp1);
	pts_oui.push_back(pp2);
	pts_oui.push_back(pp3);
	pts_oui.push_back(pp4);



	vector<Point2f> pts_dst1;													// these coordinates correspond to the readjustment area
	pts_dst1.push_back(Point2f(0, 0));
	pts_dst1.push_back(Point2f(1079, 0));
	pts_dst1.push_back(Point2f(1079, 1079));
	pts_dst1.push_back(Point2f(0, 1079));

	Mat h1 = findHomography(pts_oui, pts_dst1);									// creation of an adjustement Mat

	Mat im_out;
	cv::Size size(1080, 1080);
	warpPerspective(imgDebut, im_out, h1, size);								// output after the adjustment has been applied

	vector<Point2f> pts_non;													// shrinking of the source image
	pts_non.push_back(Point2f(0, 0));
	pts_non.push_back(Point2f(400, 0));
	pts_non.push_back(Point2f(400, 400));
	pts_non.push_back(Point2f(0, 400));
	Mat h2 = findHomography(pts_dst1, pts_non);

	Mat imgResize;
	cv::Size size2(400, 400);
	warpPerspective(im_out, imgResize, h2, size2);

	return imgResize;															// output the image we will actually use
}

vector<Point2f> rectangle(Mat imgGrayscale) {											// detection of the corners of the bir rectangle

	Mat threshold_output;
	vector<vector<cv::Point> > contours;
	vector<Vec4i> hierarchy;
	RNG rng(12345);
	threshold(imgGrayscale, threshold_output, 170, 255, THRESH_BINARY);
	findContours(threshold_output, contours, hierarchy,
		CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, cv::Point(0, 0));							// detection of the contours using suzuki85 algorithm, each contour is stoked as a vector of point

	vector<RotatedRect> minRect(contours.size());										// will contain the rectangle
	vector<RotatedRect> minEllipse(contours.size());									// can contain the ellipse if used after

	for (int i = 0; i < contours.size(); i++)
	{
		minRect[i] = minAreaRect(Mat(contours[i]));										// minAreaRect find the rectangle from the point of findContours
		if (contours[i].size() > 5)
		{
			minEllipse[i] = fitEllipse(Mat(contours[i]));								// not used
		}
	}
	vector<Point2f> pts_rect;
	Point2f p1(1, 1);
	Point2f p2(0, 1);
	Point2f p3(1, 0);
	Point2f p4(0, 0);
	pts_rect.push_back(p1);
	pts_rect.push_back(p2);
	pts_rect.push_back(p3);
	pts_rect.push_back(p4);

	Mat drawing = Mat::zeros(threshold_output.size(), CV_8UC3);							// output Mat to print the rectangle

	for (int i = 0; i< contours.size(); i++)											// this part is only to draw the rectangle
	{
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));						// each rectangle will have a random color

		int distTot = 9000;
		Point2f rect_points[4]; minRect[i].points(rect_points);
		int dist1 = (int)norm(rect_points[0] - rect_points[1]);
		int dist2 = (int)norm(rect_points[1] - rect_points[2]);
		int dist3 = (int)norm(rect_points[2] - rect_points[3]);
		int dist4 = (int)norm(rect_points[3] - rect_points[0]);
		std::cout << "rect  =   " << dist1 << "  ;  " << dist2 << " ; " << dist3 << "  ; " << dist4 << "\n";		// output the coordinates of the rectangle
		for (int j = 0; j < 4; j++) {

			int distRect = dist1 + dist2 + dist3 + dist4;
			line(drawing, rect_points[j], rect_points[(j + 1) % 4], color, 1, 8);
		}
		int distRect = dist1 + dist2 + dist3 + dist4;
		if (((dist1 <= 250 && dist1 >= 210) || (dist2 <= 250 && dist2 >= 210)) && ((dist1 <= 310 && dist1 >= 250) || (dist2 <= 310 && dist2 >= 250))) {			// this condition allow to pick only the smallest ranctangle in the range we want (might modify)
			if (distTot >distRect) {
				distTot = distRect;
				pts_rect.clear();
				for (int j = 0; j < 4; j++) {

					int distRect = dist1 + dist2 + dist3 + dist4;
					line(drawing, rect_points[j], rect_points[(j + 1) % 4], color, 1, 8);


					pts_rect.push_back(rect_points[j]);									// output the coordinates to be used in the homography
				}
			}


		}

	}

	/// Show in a window
	//namedWindow("Contours", CV_WINDOW_AUTOSIZE);
	//imshow("Contours", drawing);
	return pts_rect;
}

Mat centreImg(vector<Point2f> pts_rect, Mat imgGrayscale) {
	//puting into rectangular normalized size window

	vector<Point2f> pts_non;
	pts_non.push_back(Point2f(0, 0));
	pts_non.push_back(Point2f(400, 0));
	pts_non.push_back(Point2f(400, 400));
	pts_non.push_back(Point2f(0, 400));

	Mat h = findHomography(pts_rect, pts_non);											// Calculate Homography

	Mat im_out3;

	cv::Size size2(400, 400);
	warpPerspective(imgGrayscale, im_out3, h, size2);

	//imshow("Warped Source Image", im_out3);
	return im_out3;																		// output the normalized centered Mat we will use int the sorting functions
}

// need to comment the rest of the func
vector<Point2f> harris(Mat imgNB) {													// will be combined to the rectangle function, for the program to work even if the picture is tilted (not only rotated)
	vector<Point2f> pts_taken;														// need to comment the rest
	Mat  dst_norm, dst_norm_scaled;
	Mat dst = Mat::zeros(imgNB.size(), CV_32FC1);

	//Detector parameters
	int blockSize = 6;									//parameter for "blurr"
	int apertureSize = 5;
	double k = 0.04;
	//imshow("grayScale", imgGrayscale);
	//Detecting corners
	cornerHarris(imgNB, dst, blockSize, apertureSize, k, BORDER_DEFAULT);

	//Normalizing
	normalize(dst, dst_norm, 0, 255, NORM_MINMAX, CV_32FC1, Mat());
	convertScaleAbs(dst_norm, dst_norm_scaled);


	//Drawing a circle around corners
	int tempI = 0;
	int tempJ = 0;
	int compteur = 0;
	int tresh = 200;
	while (compteur <= 20)
	{
		compteur = 0;
		for (int j = 0; j < dst_norm.rows; j++)
		{
			for (int i = 0; i < dst_norm.cols; i++)
			{

				if ((int)dst_norm.at<float>(j, i) > tresh)
				{
					//std::cout << "aaaaaaaaaaaaaaaa" << i << "=" << j << "\n";

					if (((tempI - i) > -15 && (tempI - i) < 15) && (tempJ - j) > -15)
					{


						//std::cout << "pas bon" << i << "next" << j<<"\n";

						if (!((tempI - i) > -15 && (i - tempI) < 15)) {
							tempI = i;
						}
						if ((tempJ - j) > -15) {
							tempJ = j;
						}
					}
					else
					{
						//circle(dst_norm_scaled, Point(i, j), 5, Scalar(0), 2, 8, 0);

						//std::cout << "pas pris en compte"<<i<<j << "= lmao" << Point(i, j) 
						//	<< "lacondition"<<((tempI - i) > -15 && (tempI - i)<15) << "tempi - i="
						//	<< tempI  <<"\n";
						//std::cout << "aaaaaaaaaaaaaaaa" << i << "=" << j << "        " << tresh << "         "<<compteur<<"\n";
						//pts_taken.push_back(Point(i, j));
						compteur++;

						tempI = i;
						tempJ = j;
					}


				}
			}

		}

		tresh -= 2;
	}
	tresh += 5;
	compteur = 0;
	for (int j = 0; j < dst_norm.rows; j++) {
		for (int i = 0; i < dst_norm.cols; i++) {
			if ((int)dst_norm.at<float>(j, i) > tresh) {
				if (((tempI - i) > -10 && (tempI - i) < 10) && (tempJ - j) > -10)
				{


					//std::cout << "pas bon" << i << "next" << j<<"\n";

					if (!((tempI - i) > -10 && (i - tempI) < 10)) {
						tempI = i;
					}
					if ((tempJ - j) > -10) {
						tempJ = j;
					}
				}
				else
				{
					compteur += 1;
					circle(dst_norm_scaled, cv::Point(i, j), 5, Scalar(0), 2, 8, 0);
					pts_taken.push_back(cv::Point(i, j));
					std::cout << "aaaaaaaaaaaaaaaa" << i << "=" << j << "        " << tresh << "         " << compteur << "         " << pts_taken[0].x << "\n";
					pts_taken.push_back(cv::Point(i, j));
					compteur++;

					tempI = i;
					tempJ = j;
				}


			}
		}
	}
	//showing the result
	//namedWindow("corners_window", CV_WINDOW_AUTOSIZE);
	//imshow("corners_window", dst_norm_scaled);
	return pts_taken;
}

string triCompare(Mat im_out3) {
	CvScalar pixel1, pixel2, pixel;
	string tabmat[7];
	tabmat[0] = "LosangeP.png";
	tabmat[1] = "AngleP.png";
	tabmat[2] = "EclaireP.png";
	tabmat[3] = "FlecheP.png";
	tabmat[4] = "EclatP.png";
	tabmat[5] = "EtoileP.png";
	tabmat[6] = "TriangleP.png";
	Mat im_out4;
	threshold(im_out3, im_out4, 170, 255, CV_THRESH_BINARY);

	IplImage iplImg = (IplImage)im_out4; // passage de la matrice Mat en image 2D
	Mat im_out5;
	string soluce;
	int nombrefi = 0;
	for (int i = 0; i < 7; i++) {
		Mat imgCompa = cv::imread(tabmat[i]);                                   // open the image we need to identify

		if (imgCompa.empty()) {                                                 // verify image existence in the main repertory
			std::cout << "error: image not read from file\n\n";
			_getch();
			return(0);
		}
		threshold(imgCompa, im_out5, 170, 255, CV_THRESH_BINARY);
		int nombrePixel = 0;
		std::cout << "nombre" << nombrePixel;
		IplImage iplImg2 = (IplImage)im_out5; // passage de la matrice Mat en image 2D

		for (int f = 20; f < 380; f++) {


			for (int j = 20; j < 380; j++) {

				pixel1 = cvGet2D(&iplImg, f, j);
				pixel2 = cvGet2D(&iplImg2, f, j);

				if (pixel1.val[0] == pixel2.val[0]) {
					nombrePixel++;
					//std::cout << "nombre" << nombrePixel;
					//std::cout << 0;
					//return(0);        
				}

			}

			//std::cout << "nombre" << nombrePixel;

		}

		std::cout << "nombre" << nombrePixel;
		if (nombrePixel > nombrefi) {
			nombrefi = nombrePixel;
			soluce = tabmat[i];
		}


	}
	std::cout << soluce;
	return soluce;

}

int triRatio(Mat im_out3) {
	//harris(imgNB);
	int compteur = 0;
	int compteurPeri = 0;
	int oui = 1;
	Mat imgNB;
	threshold(im_out3, imgNB, 120, 255, CV_THRESH_BINARY);

	IplImage iplImg = (IplImage)imgNB;
	CvScalar pixel;
	CvScalar pixelComp;
	pixel = cvGet2D(&iplImg, 224, 36);
	cout << pixel.val[0] << pixel.val[1] << pixel.val[2];
	for (int j = 20; j < imgNB.rows - 20; j++)									// testing every point of the Mat
	{
		for (int i = 20; i < imgNB.cols - 20; i++)
		{





			// passage of the Mat into a readable 2D image
			pixel = cvGet2D(&iplImg, i, j);	// geting the pixel RGB value
											//cout << pixel.val[0] << pixel.val[1] << pixel.val[2];
			if (pixel.val[0] == 0) {
				//cout << 1;
				compteur++;
				for (int x = i - 1; x <= i; x++) {
					for (int y = j - 1; y <= j; y++) {
						if (i > 0 && i <= imgNB.rows && y > 0 && y <= imgNB.cols)
						{
							pixelComp = cvGet2D(&iplImg, x, y);			// testing if a neighbor pixel is white, if so the pixel is considerate as a peripheral pixel 
							if (pixelComp.val[0] == 255) {
								oui = 0;
							}
						}



					}
				}
				//cout << oui;
				if (oui == 0) {
					//cout << oui;
					compteurPeri++;
					oui = 1;
				}
			}
			else {
				//cout << 0;
			}



		}
	}
	cout << "compteur   " << compteur << "peri  " << compteurPeri << "ratio    " << (double)compteurPeri / compteur;

	//imshow("corners_window", imgNB);

	return 1;
}

int couleur(Mat imgOriginal, Mat im_out3, vector<Point2f>  pts_rect) {

	std::vector<cv::Point3f> circles;

	cv::HoughCircles(im_out3, circles, CV_HOUGH_GRADIENT, 2, 50, 100, 100, 10, 300);

	Mat imgRescale = tailleImg(imgOriginal);
	Mat couleur = centreImg(pts_rect, imgRescale);

	CvScalar pixel;
	for (size_t i = 0; i < circles.size(); i++) {
		cv::Point2i center(cvRound(circles[i].x), cvRound(circles[i].y));
		int radius = cvRound(circles[i].z);
		//namedWindow("Contours", CV_WINDOW_AUTOSIZE);
		//imshow("Contours", couleur);
		cv::circle(couleur, center, radius, CV_RGB(0, 255, 0), 3);
		std::cout << "center x=" << circles[i].x << "center y = " << circles[i].y;
		IplImage iplImg = (IplImage)couleur; // passage de la matrice Mat en image 2D
		pixel = cvGet2D(&iplImg, circles[i].x, circles[i].y);
		if (pixel.val[0] > pixel.val[1] && pixel.val[0] > pixel.val[2]) {
			std::cout << "bleu";
			return 1;
		}

		if (pixel.val[1] > pixel.val[0] && pixel.val[1] > pixel.val[2]) {
			std::cout << "vert";
			return 2;
		}

		if (pixel.val[2] > pixel.val[1] && pixel.val[2] > pixel.val[0]) {
			std::cout << "rouge";
			return 0;
		}



	}
}
