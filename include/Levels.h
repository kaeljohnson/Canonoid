#pragma once
#include <string>

namespace levels
{
	inline std::string getPlayground()
	{
		std::string levelString;
		 
		levelString += "---g----------------------------------------------";
		levelString += "--------------------------------------------------";
		levelString += "g-g--g-g------------------------------------------";
		levelString += "ggg-g---------------------------------------------";
		levelString += "--------------------------------------------------";
		levelString += "---------------------g----g--g-g------------------";
		levelString += "--------------------------------------------------";
		levelString += "--------------------------------------------------";
		levelString += "---------------------------------------ggggggggggg";
		levelString += "--------------------g------------------g----------";
		levelString += "------------g--g-g---------------------g----------";
		levelString += "gggggggggggggggggggggggg-g-------------g----------";
		levelString += "-----------------------g-ggg----gggggggg----------";
		levelString += "-----------------------g-----ggg------------------";
		levelString += "-----------------------ggggggg--------------------";

		return levelString;
	}
}