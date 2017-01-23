//
//  StageLoader.cpp
//  Catfish
//
//  Created by zhaohang on 14-4-17.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#include "StageLoader.h"
#include "FileReader.h"
#include "MikuRhythmStage.h"
#include "ResMgr.h"
#include "Rhythm.h"
#include "BackGround.h"
#include "../Math/cmlmath.h"
#include "StrUtil.h"
#include <stdlib.h>
/*
BGMUSIC
BG TEX(STR) posx(int) posy(int) scalex(float) scaley(float)  Start(float) End(float)
type(CHAR) clikTex(str) tipTex(str) posx(int) posy(int) scalex(float) scaley(float)  before(float) explode(float) ::rhythm type
*/
namespace  MikuGame
{
	StageLoader::StageLoader()
	{

	}

	StageLoader::~StageLoader()
	{

	}

	BackGround* StageLoader::CreateBG(std::string& instr)
	{
		std::string value;
		GetFirstStr(instr,value);
		BackGround* pBG = new BackGround();
		while (value=="BG")
		{
			BgPic bg;
			GetFirstStr(instr,value);
			bg.PicPath = value;
			GetFirstStr(instr,value);
			bg.Position.m_x = atoi(value.c_str());
			GetFirstStr(instr,value);
			bg.Position.m_y = atoi(value.c_str());
			GetFirstStr(instr,value);
			bg.Scale.m_x = atof(value.c_str());
			GetFirstStr(instr,value);
			bg.Scale.m_y = atof(value.c_str());

			GetFirstStr(instr,value);
			bg.StartTime = atof(value.c_str());
			GetFirstStr(instr,value);
			bg.EndTime = atof(value.c_str());
			pBG->AddBG(bg);
			GetFirstStr(instr,value);
		}
		return pBG;
	}


	Rhythm* StageLoader::CreateRhythm(std::string& instr)
	{
		std::string value;
		GetFirstStr(instr,value);
		std::string clikTex = value;
		GetFirstStr(instr,value);
		std::string tipTex = value;

		Math::vector2<int> pos;
		GetFirstStr(instr,value);
		pos.m_x = atoi(value.c_str());
		GetFirstStr(instr,value);
		pos.m_y = atoi(value.c_str());

		Math::vector2<float> scale;
		GetFirstStr(instr,value);
		scale.m_x = atof(value.c_str());
		GetFirstStr(instr,value);
		scale.m_y = atof(value.c_str());

		float before = 0.0f;
		GetFirstStr(instr,value);
		before = atof(value.c_str());

		float explode = 0.0f;
		GetFirstStr(instr,value);
		explode = atof(value.c_str());

		float last = 0.0f;
		GetFirstStr(instr,value);
		last = atof(value.c_str());

		Rhythm* ret = Rhythm::CreateRhythm(clikTex, tipTex, pos, scale, before, explode,last);
		return ret;
	}

	MikuRhythmStage* StageLoader::CreateStage(const char* path)
	{
		MikuRhythmStage* stage = new MikuRhythmStage();

		IO::FileReader reader;

		std::string filepath = Resource::ResMgr::GetInstance().GetBaseDic()+path;

		reader.OpenFile(filepath.c_str());
		long size = reader.GetSize();

		char* buffer = new char[size];
		reader.Read(size,buffer);

		std::string fileContent(buffer);
		reader.Close();

		std::string value;

		GetFirstStr(fileContent,value);
		stage->SetMusic(value.c_str());

		stage->SetBackGround(CreateBG(fileContent));

		GetFirstStr(fileContent,value);

		while (value=="R")
		{
			stage->AddRhythm(CreateRhythm(fileContent));
			GetFirstStr(fileContent,value);
		}

		delete[] buffer;
		return stage;
	}


}