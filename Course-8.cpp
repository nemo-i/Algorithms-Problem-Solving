
#include <iostream>
#include<string>
#include<iomanip>
#include<ctime>
#pragma warning (disable:4996)
int ReadNumber() {
	std::cout << "Enter Number: ";
	int Number;
	std::cin >> Number;
	return Number;
}
bool LeapYear(short Year) {
	if (Year % 400 == 0) {
		return true;
	}
	if (Year % 4 == 0 && Year % 100 != 0) {
		return true;
	}
	return false;
}

bool LeapYearShortVersion(short Year) {
	return Year % 400 == 0 ? true : (Year % 4 == 0 && Year % 100 != 0) ? true : false;
}

bool LeapYearSimplifiedVersion(short Year) {
	return Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0);
}

int NumberOfDaysInYear(short Year) {
	return LeapYear(Year) ? 366 : 365;
}
int NumberOfHoursInYear(short Year) {
	return NumberOfDaysInYear(Year) * 24;
}
int NumberOfMinutesInYear(short Year) {
	return NumberOfHoursInYear(Year) * 60;
}
int NumberOfSecondsInYear(short Year) {
	return NumberOfMinutesInYear(Year) * 60;
}

void PrintYearTimeCard() {
	short Year;
	std::cout << "Enter Year: ";
	std::cin >> Year;
	std::cout << "Number Of Days    In Year [ " << Year << " ] Is " << NumberOfDaysInYear(Year)<<std::endl;
	std::cout << "Number Of Hours   In Year [ " << Year << " ] Is " << NumberOfHoursInYear(Year) << std::endl;
	std::cout << "Number Of Minutes In Year [ " << Year << " ] Is " << NumberOfMinutesInYear(Year) << std::endl;
	std::cout << "Number Of Seconds In Year [ " << Year << " ] Is " << NumberOfSecondsInYear(Year) << std::endl;
}
std::string NumberToText(int Number) {
	std::string FromOneToNineteen[] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
	std::string FactorialOfTen[] = { "", " ", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

	if (Number == 0) {
		return " ";
	}
	if (Number >= 1 &&  Number <= 19) {
		return  FromOneToNineteen[Number] + " ";
	}
	if (Number >= 20 && Number <= 100) {
		return FactorialOfTen[Number / 10] +" "+ NumberToText(Number % 10);
	}
	if (Number >= 100 && Number <= 999) {
		return NumberToText(Number/100) +"Hundred " + NumberToText(Number % 100);
	}
	if (Number >= 1000 && Number <= 1000000) {
		return NumberToText(Number / 1000) + "Thousand " + NumberToText(Number % 1000);
	}
	if (Number >= 1000000 && Number <= 1000000000) {
		return NumberToText(Number / 1000000) + "Million " + NumberToText(Number % 1000000);
	}
	return "Not Bound";
}

short NumberOfDaysInMonth(short Month ,short Year ) {
	short DaysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	return LeapYear(Year) && Month == 2? DaysInMonth[Month] +1 :DaysInMonth[Month];
}

short NumberOfHoursInMonth(short Month, short Year) {
	return NumberOfDaysInMonth(Month, Year) * 24;
}

int NumberOfMinutesInMonth(short Month, short Year) {
	return NumberOfHoursInMonth(Month, Year) * 60;

}
int NumberOfSecondsInMonth(short Month, short Year) {
	return NumberOfMinutesInMonth(Month, Year) * 60;
}
void PrintMonthTimeCard() {
	short Year;
	std::cout << "Enter Year: ";
	std::cin >> Year;
	short Month;
	std::cout << "Enter Month: ";
	std::cin >> Month;
	std::cout << "Number Of Days    In Month [ " << Month << " ] Is " << NumberOfDaysInMonth(Month,Year) << std::endl;
	std::cout << "Number Of Hours   In Month [ " << Month << " ] Is " << NumberOfHoursInMonth(Month, Year) << std::endl;
	std::cout << "Number Of Minutes In Month [ " << Month << " ] Is " << NumberOfMinutesInMonth(Month, Year) << std::endl;
	std::cout << "Number Of Seconds In Month [ " << Month << " ] Is " << NumberOfSecondsInMonth(Month, Year) << std::endl;
}



short DayOfWeekOrder(short Year , short Month , short Day){
	short a = (14 - Month) / 12;
	short y = Year - a;
	short m = Month + (12 * a) - 2;
	short d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	return d;
}

std::string DayNameOfTheWeek(short DayPos) {
	std::string daysName[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	return daysName[DayPos];
}

short ReadYear() {
	short year;

	std::cout << "Enter a year: ";
	std::cin >> year;
	return year;
}
short ReadMonth() {
	short month;
	std::cout << "Enter a month: ";
	std::cin >> month;
	return month;
}
short ReadDay() {
	short day;
	std::cout << "Enter a day: ";
	std::cin >> day;
	return day;
}
void PrintDateCard() {
	short year  = ReadYear();
	short month = ReadMonth();
	short day = ReadDay();
	short dayPos = DayOfWeekOrder(year, month, day);
	std::string dayName = DayNameOfTheWeek(dayPos);
	std::cout << "Date      :" << day << "/" << month << "/" << year<<std::endl;
	std::cout << "Day Order :" << dayPos<<std::endl;
	std::cout << "Day Name  :" << dayName<<std::endl;

}

std::string MonthName(short Month , bool ShortVersion = true) {
	std::string fullMonthsName[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	std::string shortMonthsName[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	return ShortVersion? shortMonthsName[Month-1]:fullMonthsName[Month-1];
}
std::string DayName(short Day , bool ShortVersion = true){
	std::string fullDaysName[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	std::string shortDaysName[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
	return ShortVersion? shortDaysName[Day]:fullDaysName[Day];
}

void PrintDashLineWithMonthNameInMiddle(std::string MonthName , short LineLength = 40) {
	
	short dashBeforeMonthName = (LineLength - MonthName.length()) / 2;
	short dashAfterMonthName = LineLength - MonthName.length() - dashBeforeMonthName;
	std::cout << std::string(dashBeforeMonthName,'-') << MonthName << std::string(dashAfterMonthName,'-')<<std::endl;
}
void PrintDashLine(short LineLength = 40) {
	std::cout << std::string(LineLength, '-') << std::endl;
}

void PrintClanderHeader() {
	std::string shortDaysName[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
	for (auto& i : shortDaysName)
	{
		std::cout<<std::setw(5)<<i;
	}
	std::cout << '\n';
}

void GenerateCalnderDays(short* Days, short Year,short Month,short Day) {
	short startDayOfMonth = DayOfWeekOrder(Year, Month, Day);
	short daysInMonth = NumberOfDaysInMonth(Month,Year);
	short counter = 1;
	for (size_t i = 0; i < 35; i++)
	{
		if ((i >= startDayOfMonth) && (counter <= daysInMonth)) {
			Days[i] = counter;
			counter++;
		}
		else
		{
			Days[i] = 0;
		}
		
	}
	
}

void PrintCalnderDays(short Year,short Month) {
	short days[35];
	GenerateCalnderDays(days,Year,Month,1);
	for (size_t i = 0; i < 35; i++)
	{
		if (days[i] != 0) {
			std::cout << std::setw(5) << days[i];
		}
		else
		{
			std::cout << std::setw(5) << "";
		}
		if (i % 7 == 6 && i != 34) { // New line after each complete week, avoid extra line at the end
			std::cout << "\n";
		}
		
	}
	std::cout << '\n';
}
void PrintCalenderCard(short Year,short Month) {
	//short year = ReadYear();
	//short month = ReadMonth();
	PrintDashLineWithMonthNameInMiddle(MonthName(Month));
	PrintClanderHeader();
	PrintCalnderDays(Year, Month);
	PrintDashLine();
}
void PrintCharacterBeforeAndAfterText(std::string Text, char Char = '-' , short LineLength = 40) {
	short characterBefore = (LineLength - Text.length()) / 2;
	short characterAfter = LineLength - Text.length() - characterBefore;
	std::cout << std::string(characterBefore, Char) << Text << std::string(characterAfter, Char)<<std::endl;
}

std::string  GenerateCalenderTextWithYear(short Year){
	return "Calender - "+ std::to_string(Year);
}
void PrintYearCalenderHeader(short Year) {
	PrintDashLine();
	PrintCharacterBeforeAndAfterText(GenerateCalenderTextWithYear(Year),' ');
	PrintDashLine();
}

void PrintYearCalender() {
	
	short year = ReadYear();
	PrintYearCalenderHeader(year);
	for (size_t i = 1; i <= 12; i++)
	{
		PrintCalenderCard(year,i);
		std::cout<<'\n';
	}
}

short HowManyDaysSinceStartOfTheYear(short Year, short Month, short Day) {
	short counter = 0;
	for (size_t i = 1; i < Month; i++)
	{
	 counter +=	NumberOfDaysInMonth(i, Year);
	}
	counter += Day;
	return counter;
}
void PrintHowManyDaysSinceStartOfTheYear() {
	short day = ReadDay();
	short month = ReadMonth();
	short year = ReadYear();

	std::cout << "Number of days from the begining of the year is " << HowManyDaysSinceStartOfTheYear(year, month, day)<<std::endl;
}

struct  Date
{
	int year;
	short month;
	short day;
};
Date DateFromDays(short Year , short Days) {
	short month=1;
	Date date = {0};
	for (size_t i = 1; i <= 12; i++)
	{
		short daysInMonth = NumberOfDaysInMonth(i, Year);
		if ((Days > 28) && (Days > daysInMonth)) {
			Days -= daysInMonth;
			month ++;
		}
		else
		{
			break;
		}	

	}
	date.year = Year;
	date.month = month;
	date.day = Days;
	return date;
}
// hello test somthing in git

Date AddDaysToDate(Date sDate,short Days) {
	short currentYearCounter = sDate.year;
	short days = Days + HowManyDaysSinceStartOfTheYear(sDate.year, sDate.month, sDate.day);
	while (true)
	{
		short daysInYear = NumberOfDaysInYear(currentYearCounter);
		if (days > daysInYear) {
			days -= daysInYear;
			currentYearCounter++;
		}
		else
		{
		  sDate =DateFromDays(currentYearCounter,days);
		  break;
		}
	}
	return sDate;
}

Date ReadDate() {
	Date date = { 0 };
	date.year= ReadYear();
	date.month = ReadMonth();
	date.day = ReadDay();
	return date;
}
void PrintDate(Date date){
	std::cout << date.day << "/" << date.month << "/" << date.year<<'\n';
}
void PrintAddDaysToDate() {
	Date readDate = ReadDate();
	short days = ReadDay();
	Date date = AddDaysToDate(readDate, days);
	PrintDate(date);
}
bool DateOneLessThanDateTwo(Date sDateOne, Date sDateTwo){
	if (sDateOne.year < sDateTwo.year)return true;
	if (sDateOne.year == sDateTwo.year) {
		if (sDateOne.month < sDateTwo.month) {
			return true;
		}
		if (sDateOne.month == sDateTwo.month) {
			if (sDateOne.day < sDateTwo.day) {
				return true;
			}
		}
		
	}
	return false;
}

void PrintDateLess() {
	Date dateOne = ReadDate();

	Date dateTwo = ReadDate();

	if (DateOneLessThanDateTwo(dateOne, dateTwo)) {
		PrintDate(dateOne);
		std::cout << " Less Than ";
		PrintDate(dateTwo);
	}
	else
	{
		PrintDate(dateOne);
		std::cout << " Not Less Than ";
		PrintDate(dateTwo);
	}
}
bool DateEqualDateTwo(Date sDateOne, Date sDateTwo) {
	return (sDateOne.year == sDateTwo.year) && (sDateOne.month == sDateTwo.month) && (sDateOne.day == sDateTwo.day);
}

bool IsLastDayInMonth(Date sDate) {
	return sDate.day == NumberOfDaysInMonth(sDate.month, sDate.year);
}
bool IsLastMonthInYear(Date sDate) {
	return sDate.month == 12;
}

Date AddOneDayToDate(Date sDate) {
	Date date = {0};
	if (IsLastDayInMonth(sDate) && IsLastMonthInYear(sDate)) {
		date.year = ++sDate.year;
		date.month = 1;
		date.day = 1;
		return date;
	}
	if (IsLastDayInMonth(sDate)) {
		date.year = sDate.year;
		date.month = ++sDate.month;
		date.day = 1;
		return date;
	}
	date.year = sDate.year;
	date.month = sDate.month;
	date.day = ++sDate.day;
	return date;
}
void PrintAddOneDayToDate() {
	Date date = ReadDate();
date = 	AddOneDayToDate(date);
	PrintDate(date);
}


short DiffInDate(Date sDateOne, Date sDateTwo) {
	int counter = 0;
	Date spawedDate = {0};
	if (!DateOneLessThanDateTwo(sDateOne, sDateTwo)) {
		spawedDate = sDateOne;
		sDateOne = sDateTwo;
		sDateTwo = spawedDate;
	}
	while (!DateEqualDateTwo(sDateOne,sDateTwo))
	{
	sDateOne =AddOneDayToDate(sDateOne);
	counter++;
	}
	return counter;
}

void PrintDiffInDate() {
	Date dateOne = ReadDate();
	Date dateTwo = ReadDate();
short diff = 	DiffInDate(dateOne,dateTwo);
std::cout << diff << " Days " << "\n";
}
Date GetSystemDate() { 
	Date Date; time_t t = time(0);
	tm* now = localtime(&t);    
	Date.year = now->tm_year + 1900; 
	Date.month = now->tm_mon + 1;     
	Date.day = now->tm_mday; return Date; }

int CalAgeInDays(Date BirthDate) {
	
return	DiffInDate(BirthDate,GetSystemDate());
}
void PrintCalAgeInDays() {
	Date birthDate = ReadDate();
int ageInDays =	CalAgeInDays(birthDate);

std::cout << ageInDays << '\n';
}

Date IncreaseDateByXDays(Date sDate,int Days) {
	
		sDate = AddDaysToDate(sDate,Days);
		return sDate;
}

Date IncreaseDateByOneWeek(Date sDate) {
return	IncreaseDateByXDays(sDate,7);
}
Date IncreaseDateByXWeeks(Date sDate,short Weeks) {
	for (size_t i = 0; i < Weeks; i++)
	{
	 sDate = IncreaseDateByOneWeek(sDate);
	}
	return sDate;
}
Date IncreaseDateByOneMonth(Date sDate) {
	if (IsLastMonthInYear(sDate)) {
		sDate.year++;
		sDate.month = 1;
		
	}
	else
	{
		sDate.month++;
		
	}
short numberOfDayInThisMonth=	NumberOfDaysInMonth(sDate.month,sDate.year);
if (sDate.day > numberOfDayInThisMonth) {
	sDate.day = sDate.day - numberOfDayInThisMonth;
	sDate.month++;
}


	return sDate;
}
Date IncreaseDateByXMonth(Date sDate, short Months) {
	for (size_t i = 0; i < Months; i++)
	{
		sDate = IncreaseDateByOneMonth(sDate);
		
	}return sDate;
}

Date IncreaseDateByOneYear(Date sDate) {
	sDate.year++;
	return sDate;
}
Date IncreaseDateByXYears(Date sDate, short Years) {
	sDate.year = sDate.year + Years;
	return sDate;
}

Date InceraseDateByOneDeacade(Date sDate) {
	sDate = IncreaseDateByXYears(sDate, 10);
	return sDate;
}
Date IncreaseDateByXDeacde(Date sDate, short Decades) {
	sDate.year = sDate.year + (10 *Decades);
	return sDate;
}
Date IncreaseDateByOneCentury(Date sDate) {
	sDate = IncreaseDateByXDeacde(sDate,10);
	return sDate;
}
Date IncreaseDateByOneMillennium(Date sDate) {
	sDate.year = sDate.year + 1000;
	return sDate;
}
Date DecreaseDateByOneDay(Date sDate) {
	if (sDate.day == 1 && sDate.month !=1) {
		sDate.month -= 1;
		sDate.day = NumberOfDaysInMonth(sDate.month,sDate.year);
		return sDate;
	}
	if (sDate.day == 1 && sDate.month == 1) {
		sDate.year -= 1;
		sDate.month = 12;
		sDate.day = NumberOfDaysInMonth(sDate.month,sDate.year);
		return sDate;
	}
	
	sDate.day = sDate.day--;

	return sDate;
}
Date DecreaseDateByXDays(Date sDate,short Days) {
	for (size_t i = 0; i < Days; i++)
	{
		sDate = DecreaseDateByOneDay(sDate);
	}
	return sDate;
}
Date DecreaseDateByOneWeek(Date sDate) {
	
		sDate = DecreaseDateByXDays(sDate, 7);
	
	return sDate;
}
Date DecreaseDateByXWeeks(Date sDate, short Weeks) {
	for (size_t i = 0; i < Weeks; i++)
	{
		sDate = DecreaseDateByOneWeek(sDate);
	}
	return sDate;
}
Date DecreaseDateByOneMonth(Date sDate) {
	if (sDate.month == 1) {
		sDate.year--;
		sDate.month = 12;
		
		return sDate;
	}
	if (sDate.month > 2 && sDate.day > 29 )  {
		sDate.month--;
		sDate.day = NumberOfDaysInMonth(sDate.month, sDate.year);
		return sDate;
	}
	sDate.month--;
	return sDate;
}
Date DecreaseDateByXMonth(Date sDate,short Months) {
	for (size_t i = 0; i < Months; i++)
	{
		sDate = DecreaseDateByOneMonth(sDate);
	}
	return sDate;
}
Date DecreaseDateByOneYear(Date sDate) {
	sDate.year--;
	return sDate;
}
Date DecreaseDateByXYears(Date sDate, int Years) {
	sDate.year -= Years;
	return sDate;
}
Date DecreaseDateByOneDecade(Date sDate, int Decades) {
	sDate.year -= (Decades * 10);
	return sDate;
}
Date DecreaseDateByOneCentury(Date sDate) {
	sDate.year -= (100);
	return sDate;
}
Date DecreaseDateXCenturies(Date sDate, int Centuries) {
	sDate.year -= (100 * Centuries);
	return sDate;
}
Date DecreaseDateByOneMilinia(Date sDate) {
	sDate.year -= 1000;
	return sDate;
}
short DayOfWeekOrder(Date sDate) {
	short	a = (14 - sDate.month) / 12;
	short y = sDate.year - a;
	short m = sDate.month + (12 * a) - 2;
	short d = (sDate.day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	return d;
}
bool IsEndOfWeek(Date sDate) {
	return DayOfWeekOrder(sDate) == 6;
}

bool IsWeekendDay(Date sDate) {
	return (DayOfWeekOrder(sDate) == 5 || DayOfWeekOrder(sDate) == 6);
}
bool IsBusinessDay(Date sDate) {
	return !IsWeekendDay(sDate);
}

short DaysUntilTheEndOfTheWeek(Date sDate) {
	return 6- DayOfWeekOrder(sDate) ;
}
short DaysUntilTheEndOfTheMonth(Date sDate, bool IncludeCurrentDay = true) {
 return	NumberOfDaysInMonth(sDate.month, sDate.year) - sDate.day + (IncludeCurrentDay?1:0);
}
short DaysUntilTheEndOfTheYear(Date sDate, bool IncludeCurrentDay = true) {
	short yearDays;
	if (LeapYearSimplifiedVersion(sDate.year)) {
		yearDays = 366;
	}
	else
	{
		yearDays = 365;
	}
return 	yearDays - HowManyDaysSinceStartOfTheYear(sDate.year, sDate.month, sDate.day) + (IncludeCurrentDay ? 1 : 0);
}

short VacationPeriod(Date StartDate, Date EndDate) {
	short vaction = 0;
	while (DateOneLessThanDateTwo(StartDate,EndDate))
	{
		
		if (IsBusinessDay(StartDate)) {
			vaction++;
		}
	StartDate = 	AddOneDayToDate(StartDate);
	}
	return vaction;
}

Date VactionReturnDate(Date StartDate, short VactionDays) {
	Date returnDate = StartDate;
	short weekend = 0;

	while (IsWeekendDay(returnDate))
	{
		returnDate = AddOneDayToDate(returnDate);
	}
	for (size_t i = 0; i < VactionDays; i++)
	{
		if (IsWeekendDay(returnDate)) {
			weekend++;
			std::cout << weekend<<std::endl;
		}
		returnDate = AddOneDayToDate(returnDate);
	}
	returnDate =  AddDaysToDate(returnDate, (weekend));
	
	while (IsWeekendDay(returnDate))
	{
		std::cout << "Here";
		returnDate = AddOneDayToDate(returnDate);
	}
	return returnDate;
}
Date CalculateVacationReturnDate(Date DateFrom, short VacationDays)
{

	short WeekEndCounter = 0;

	//in case the data  is weekend keep adding one day util you reach business day
	//we get rid of all weekends before the first business day
	while (IsWeekendDay(DateFrom))
	{
		DateFrom = AddOneDayToDate(DateFrom);
	}
	

	//here we increase the vacation dates to add all weekends to it.

	for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
	{

		if (IsWeekendDay(DateFrom))
			WeekEndCounter++;

		DateFrom = AddOneDayToDate(DateFrom);
	}
	

	//in case the return date is week end keep adding one day util you reach business day
	while (IsWeekendDay(DateFrom))
	{
		DateFrom = AddOneDayToDate(DateFrom);
	}

	return DateFrom;
}

bool IsDateOneEqualDateTwo(Date DateOne, Date DateTwo) {
	return DateOne.year == DateTwo.year && DateOne.month == DateTwo.month && DateOne.day == DateTwo.day;
}
bool IsDateOneAfterDateTwo(Date DateOne, Date DateTwo) {
	return !DateOneLessThanDateTwo(DateOne,DateTwo) && !IsDateOneEqualDateTwo(DateOne,DateTwo);
}
short CompareDateFunction(Date DateOne, Date DateTwo) {
	if(IsDateOneAfterDateTwo(DateOne, DateTwo)) {
		return 1;
	}
	else if (IsDateOneEqualDateTwo(DateOne,DateTwo))
	{
		return 0;
	}
	return -1;
}
struct  sPeriod
{
	Date startDate;
	Date endDate;
};
bool IsTwoPeriodOverlap(sPeriod PeriodOne, sPeriod PeriodTwo) {
	short start = CompareDateFunction(PeriodOne.startDate,PeriodTwo.startDate);
	short end = CompareDateFunction(PeriodOne.endDate, PeriodTwo.startDate);
	if (start == end && start!=0 && end !=0) return false;
	return true;
}
int CalculatePeriodLength(sPeriod Period , bool IncludeEndDate = false) {
	int periodLength = 0;
	while (!IsDateOneEqualDateTwo(Period.startDate, Period.endDate))
	{
		periodLength++;
		Period.startDate = AddOneDayToDate(Period.startDate);
	}
	return periodLength;
}

bool IsDateWithinGivenPeriod(sPeriod Period, Date sDate) {
	sPeriod periodTwo;
	periodTwo.startDate = sDate;
	periodTwo.endDate = sDate;
	return IsTwoPeriodOverlap(Period,periodTwo);

}


short OverlapedPeriod(sPeriod PeriodOne, sPeriod PeriodTwo) {
	short overlapPeriod = 0;
	if (!IsTwoPeriodOverlap(PeriodOne, PeriodTwo)) {
		return 0;
	}
	else
	{
		if (DateOneLessThanDateTwo(PeriodOne.startDate, PeriodTwo.startDate)) {
			while (DateOneLessThanDateTwo(PeriodTwo.startDate, PeriodOne.endDate))
			{
				overlapPeriod++;
				PeriodTwo.startDate = AddOneDayToDate(PeriodTwo.startDate);
			}
		}
		else {
			while (DateOneLessThanDateTwo(PeriodOne.startDate, PeriodTwo.endDate))
			{
				overlapPeriod++;
				PeriodOne.startDate = AddOneDayToDate(PeriodOne.startDate);
			}
		}
		
	}

	return overlapPeriod;
}
int CountOverlapDays(sPeriod Period1, sPeriod Period2)
{
	int Period1Length = CalculatePeriodLength(Period1, true); int Period2Length = CalculatePeriodLength(Period2, true); int OverlapDays = 0; if (!IsTwoPeriodOverlap(Period1, Period2)) return 0; if (Period1Length < Period2Length) { while (DateOneLessThanDateTwo(Period1.startDate, Period1.endDate)) { if (IsDateWithinGivenPeriod(Period2, Period1.startDate))                 OverlapDays++; Period1.startDate = AddOneDayToDate(Period1.startDate); } }
	else { while (DateOneLessThanDateTwo(Period2.startDate, Period2.endDate)) { if (IsDateWithinGivenPeriod(Period1, Period2.startDate))                 OverlapDays++; Period2.startDate = AddOneDayToDate(Period2.startDate); } } return OverlapDays;
}

int main()
{

	sPeriod periodOne;
	periodOne.startDate = Date{2022,1,1};
	periodOne.endDate = Date{ 2022,1,10 };
	
	sPeriod periodTwo;
	periodTwo.startDate = Date{ 2022,1,5 };
	periodTwo.endDate = Date{ 2050,12,30 };
	std::cout << OverlapedPeriod(periodOne,periodTwo);

}

