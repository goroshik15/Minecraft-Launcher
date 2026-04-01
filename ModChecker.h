#pragma once
#include <vector>
#include <string>

using namespace System;
using namespace std;

public class ModChecker
{
public:
    ModChecker();
    void CheckMods();
	vector<string> existingMods;
	vector<string> folderMods;
};