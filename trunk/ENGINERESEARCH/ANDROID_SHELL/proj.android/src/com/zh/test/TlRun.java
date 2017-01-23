package com.zh.test;

import java.io.File;

import org.cocos2dx.lib.Cocos2dxActivity;

import android.os.Bundle;
import android.util.Log;

public class TlRun extends Cocos2dxActivity{

	protected void onCreate(Bundle savedInstanceState){
		super.onCreate(savedInstanceState);
		System.loadLibrary("FreeImaged");
		System.loadLibrary("Lua");
		System.loadLibrary("IO");
		System.loadLibrary("GlesSystem");
		System.loadLibrary("ScriptSystem");
		System.loadLibrary("SoundSystem");
		System.loadLibrary("ResourcePhraser");
        System.loadLibrary("Demo");
	}
	
	protected void onDestroy()
	{
		super.onDestroy();
	}
	
	static {  
		
   }
}