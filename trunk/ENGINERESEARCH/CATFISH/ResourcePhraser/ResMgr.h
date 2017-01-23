#ifndef RESMGR_H_
#define RESMGR_H_
#include "RDllCommon.h"
#include <map>
#include <string>
#include "../Math/hash.h"
namespace Resource
{
    static const char* Sprite2DShader = "Sprite2DShader";
	static const char* Default3DShader = "Default3DShader";
    static const char* FontShader = "FontShader";
    static const char* DefaultRect = "DefaultRect";
    
	class Res;
	class RES_API ResMgr
	{
	public:
		~ResMgr();
		static ResMgr& GetInstance()
		{
			static ResMgr instance;
			return instance;
		}

		void InitPhasers();//only for free image, fuck.
		void DestoryPhasers();//only for free image, fuck.
		void InitDefaultResource();
        void SetBaseDic(const char* basePath);
        const std::string& GetBaseDic();
		template<typename T> T* GetRes(const char* path);
        
        template<typename T> T* GetRes(const char* base,const char* path);

	protected:
		ResMgr();
		std::map<unsigned int,Res*> m_ResMap;
        std::string m_strBasePath;
	private:
	};

	template<typename T>
	T* ResMgr::GetRes( const char* path )
	{
        std::string allpath = m_strBasePath+std::string(path);
		int hash = BKDRHash(const_cast<char*>(allpath.c_str()));
		std::map<unsigned int,Res*>::iterator itr = m_ResMap.find( hash);
		T* res;
		if ( itr==m_ResMap.end() )
		{
			res = new T();
			res->Load(allpath.c_str());
			m_ResMap.insert(std::make_pair(hash,(Res*)res));
		}
		else
		{
			res = (T*)(*itr).second;
		}
		return res;
	}
    
    template<typename T>
	T* ResMgr::GetRes( const char* base,const char* path )
	{
        std::string _base(base);
        std::string _path(path);
        std::string all =_base+_path;
		int hash = BKDRHash(const_cast<char*>(all.c_str()));
		std::map<unsigned int,Res*>::iterator itr = m_ResMap.find( hash);
		T* res;
		if ( itr==m_ResMap.end() )
		{
			res = new T();
			res->Load(all.c_str());
			m_ResMap.insert(std::make_pair(hash,(Res*)res));
		}
		else
		{
			res = (T*)(*itr).second;
		}
		return res;
	}

}
#endif