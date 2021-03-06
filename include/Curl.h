/***************************************************************************** 
* 
* PROJECT: MTADiag
* LICENSE: GNU GPL v3
* FILE: Curl.h
* PURPOSE: Header for cURL functions
* DEVELOPERS: Matthew "Towncivilian" Wolfe <ligushka@gmail.com>
* 
* 
* 
* Multi Theft Auto is available from http://www.multitheftauto.com/
* 
*****************************************************************************/ 

#pragma once

#include "Common.h"

namespace Curl {

	bool                  DownloadFile            ( std::string fileURL, std::string filePath );
	std::string           CreateMTAPasteBin       ( std::string filePath, std::string pasteName );
	std::string           CreatePasteBin          ( std::string filePath, std::string pasteName );
	static std::string    response;               // HTTP POST response
}