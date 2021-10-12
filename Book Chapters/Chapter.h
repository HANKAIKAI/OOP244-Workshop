// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================
// Name:           Yuankai Han
// Student Number: 154477194
// Email:          yhan77@myseneca.ca
// Section:        NAA
// Date:           2021.10.
//==============================================
// Worshop#4: (DIY) Constructors, Destructors and Current object 
// Version: 0.9
//==============================================
#ifndef _SDDS_CHAPTER_H
#define _SDDS_CHAPTER_H
namespace sdds{
	const int MAX_NAME_LEN = 50;
	const int MAX_PAGE_LEN = 200;

	class Chapter{
	private:
		int m_noOfPage;
		char m_name[MAX_NAME_LEN + 1];
	public:
		Chapter();
		Chapter(const char* name, int noOfPage);
		void setEmpty();
		bool isEmpty()const;
		void setChapterName(const char* name);
		void setNoOfPage(int noOfPage);
		const char* getChapterName()const;
		int getNoOfPage()const;
		void display()const;
	};
}
#endif // !_SDDS_CHAPTER_H
