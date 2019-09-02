int leapyear (int yr)
{
	bool leap;
		if ((yr % 4 == 0) && !(yr % 100 == 0)|| (yr % 400 == 0))
			leap = true;
		else
			leap = false;
	return leap;
}
