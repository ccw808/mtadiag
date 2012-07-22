/***************************************************************************** 
* 
* PROJECT: MTADiag
* LICENSE: GNU GPL v3
* FILE: util.cpp
* PURPOSE: Utility functions
* DEVELOPERS: Matthew "Towncivilian" Wolfe <ligushka@gmail.com>
* 
* 
* 
* Multi Theft Auto is available from http://www.multitheftauto.com/
* 
*****************************************************************************/ 

#include "util.h"

std::string ReadRegKey ( std::string value, std::string subkey )
{
	HKEY hKey = 0; // handle to registry key
	char buf[255] = {0}; // buffer for reading
	DWORD dwType = 1; // REG_SZ
	DWORD dwBufSize = sizeof ( buf ); // buffer size

	if ( RegOpenKey ( HKEY_LOCAL_MACHINE, subkey.c_str(), &hKey ) == ERROR_SUCCESS ) // registry key read was successful
	{
		if ( RegQueryValueEx ( hKey, value.c_str(), NULL, &dwType, ( BYTE* ) buf, &dwBufSize ) == ERROR_SUCCESS ) // registry value read was successful
		{
			std::string value ( buf ); // store the value
			RegCloseKey ( hKey ); // close the registry key
			return value; // return the value
		}
		else
		{
			RegCloseKey ( hKey ); // close the registry key
			return "Can not query value."; // unable to query value
		}
	}
	else
	{
		return "Failed to read key."; // unable to read registry key
	}
}

bool CheckForFile ( std::string FilePath )
{
	std::ifstream ifile ( FilePath.c_str() );
	if ( ifile )
		return true;
	else
		return false;
}

void ConvertUnicodeToASCII ( std::string file1, std::string file2 )
{
	std::stringstream ss; // create a stringstream
	std::string convert;

	ss << "TYPE " << file1 << " > " << file2; // TYPE <file1> > <file2>
	convert = ss.str ();

	// clear the stringstream
	ss.str ("");
	ss.clear();

	system ( convert.c_str() ); // do it
}

// slightly modified version of http://msdn.microsoft.com/en-us/library/ms724451%28VS.85%29.aspx
bool IsVistaOrNewer ( void )
{
	OSVERSIONINFO osvi;
	bool bIsVistaOrNewer;

	ZeroMemory ( &osvi, sizeof ( OSVERSIONINFO ) );
	osvi.dwOSVersionInfoSize = sizeof ( OSVERSIONINFO );

	GetVersionEx ( &osvi );

	if ( bIsVistaOrNewer = ( osvi.dwMajorVersion >= 6 ) )
		return true;
	else
		return false;
}