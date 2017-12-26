#pragma once
#ifndef _GETFILENAME_H
#define _GETFILENAME_H

#include <string>

std::string GetFilename(std::string file) {
	std::reverse(begin(file), end(file));
	auto iter = file.begin();
	std::string ret = "";
	while (*iter != '\\') {
		ret.insert(begin(ret), *iter);
		iter++;
	}
	return ret;
}
#endif // !_GETFILENAME_H