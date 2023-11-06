// zavd_91.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> 

using namespace std;

class Massage {
public:

	virtual void setHeader() = 0;
	virtual void setText() = 0;
	virtual void setFooter() = 0;

	virtual void printResult() = 0;
};

class SmsMassage : public Massage {
private:
	string header;
	string text;
	string footer;
public:

	void setHeader() override {
		this->header = "sms header";
	}

	void setText() override {
		this->text = "sms text";
	}

	void setFooter() override {
		this->footer = "sms footer";
	}

	void printResult() override {
		cout << header << " " << text << " " << footer << endl;
	}
};

class EmailMassage : public Massage {
private:
	string header;
	string text;
	string footer;
public:

	void setHeader() override {
		this->header = "email header";
	}

	void setText() override {
		this->text = "email text";
	}

	void setFooter() override {
		this->footer = "email footer";
	}

	void printResult() override {
		cout << header << endl;
		cout << text << endl;
		cout << footer << endl;
	}

};

class Builder {
public:

	virtual void createHeader() = 0;
	virtual void createText() = 0;
	virtual void createFooter() = 0;

	virtual Massage* build() = 0;

};


class EmailBuilder : public Builder {
private:
	Massage* massage = new EmailMassage();

public:


	void createHeader() override {
		massage->setHeader();
	}

	void createText() override {
		massage->setText();
	}

	void createFooter() override {
		massage->setFooter();
	}

	Massage* build() override {
		return massage;
	}
};

class SmsBuilder : public Builder {
private:

	Massage* massage = new SmsMassage();
public:

	void createHeader() override {
		massage->setHeader();
	}

	void createText() override {
		massage->setText();
	}

	void createFooter() override {
		massage->setFooter();
	}

	Massage* build() override {
		return massage;
	}
};


int main()
{
	Builder* builder = new EmailBuilder();

	builder->createHeader();
	builder->createText();


	Massage* massage = builder->build();

	massage->printResult();
}