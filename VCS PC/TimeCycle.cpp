#include "StdAfx.h"
#include "TimeCycle.h"

#include "Weather.h"
#include "PostEffects.h"
#include "Clock.h"
#include "Coronas.h"
#include "CullZones.h"
#include "CutsceneManager.h"
#include "Timer.h"
#include "Shadows.h"
#include "Camera.h"
#include "debugmenu_public.h"

uint8 CTimeCycle::m_nDirectionalMult[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_nWaterFogAlpha[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_nHighLightMinIntensity[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_fCloudAlpha[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_fPostFx2Alpha[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_fPostFx2Blue[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_fPostFx2Green[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_fPostFx2Red[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_fPostFx1Alpha[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_fPostFx1Blue[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_fPostFx1Green[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_fPostFx1Red[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_fWaterAlpha[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_fWaterBlue[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_fWaterGreen[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_fWaterRed[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_nFluffyCloudsBottomRed[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_nFluffyCloudsBottomGreen[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_nFluffyCloudsBottomBlue[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_nLowCloudsBlue[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_nLowCloudsGreen[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_nLowCloudsRed[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_fLightsOnGroundBrightness[NUMHOURS][NUMWEATHERS];
int16 CTimeCycle::m_fFogStart[NUMHOURS][NUMWEATHERS];
int16 CTimeCycle::m_fFarClip[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_nPoleShadowStrength[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_nLightShadowStrength[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_nShadowStrength[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_fSpriteBrightness[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_fSpriteSize[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_fSunSize[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_nSunCoronaBlue[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_nSunCoronaGreen[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_nSunCoronaRed[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_nSunCoreBlue[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_nSunCoreGreen[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_nSunCoreRed[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_nSkyBottomBlue[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_nSkyBottomGreen[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_nSkyBottomRed[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_nSkyTopBlue[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_nSkyTopGreen[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_nSkyTopRed[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_nAmbientBlue_Obj[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_nAmbientGreen_Obj[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_nAmbientRed_Obj[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_nAmbientBlue[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_nAmbientGreen[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_nAmbientRed[NUMHOURS][NUMWEATHERS];

// VCS
uint8 CTimeCycle::m_nAmbientRed_Bl[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_nAmbientGreen_Bl[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_nAmbientBlue_Bl[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_nAmbientRed_Obj_Bl[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_nAmbientGreen_Obj_Bl[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_nAmbientBlue_Obj_Bl[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_nDirectionalRed[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_nDirectionalGreen[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_nDirectionalBlue[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_nRadiosityIntensity[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_nRadiosityLimit[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_nFluffyCloudsTopRed[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_nFluffyCloudsTopGreen[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_nFluffyCloudsTopBlue[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_fBlurRed[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_fBlurGreen[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_fBlurBlue[NUMHOURS][NUMWEATHERS];
float CTimeCycle::m_fBlurAlpha[NUMHOURS][NUMWEATHERS];
float CTimeCycle::m_fBlurOffset[NUMHOURS][NUMWEATHERS];

float &CTimeCycle::m_BrightnessAddedToAmbientRed = *(float*)0xB79E38;
float &CTimeCycle::m_BrightnessAddedToAmbientGreen = *(float*)0xB79E34;
float &CTimeCycle::m_BrightnessAddedToAmbientBlue = *(float*)0xB79E30;

int &CTimeCycle::m_ExtraColourWeatherType = *(int*)0xB79E40;
int &CTimeCycle::m_ExtraColour = *(int*)0xB79E44;
int &CTimeCycle::m_bExtraColourOn = *(int*)0xB7C484;
float &CTimeCycle::m_ExtraColourInter = *(float*)0xB79E3C;
CVector &CTimeCycle::m_vecDirnLightToSun = *(CVector*)0xB7CB14;
int &CTimeCycle::m_FogReduction = *(int*)0xB79E48;
CVector *CTimeCycle::m_VectorToSun = (CVector*)0xB7CA50;
float *CTimeCycle::m_fShadowFrontX = (float*)0xB79F90;
float *CTimeCycle::m_fShadowFrontY = (float*)0xB79F50;
float *CTimeCycle::m_fShadowSideX = (float*)0xB79F10;
float *CTimeCycle::m_fShadowSideY = (float*)0xB79ED0;
float *CTimeCycle::m_fShadowDisplacementX = (float*)0xB79E90;
float *CTimeCycle::m_fShadowDisplacementY = (float*)0xB79E50;
int &CTimeCycle::m_CurrentStoredValue = *(int*)0xB79FD0;
RwRGBA &CTimeCycle::m_BelowHorizonGrey = *(RwRGBA*)0xB7CB10;
CColourSet CTimeCycle::m_CurrentColours;
CColourSet &CTimeCycle::m_CurrentColours_exe = *(CColourSet*)0xB7C4A0;

static Reversed StartExtraColour_kill(0x55FEC0 + 5, 0x55FF1F);
void
CTimeCycle::StartExtraColour(int extracolor, int keepInter)
{
	CTimeCycle::m_ExtraColourWeatherType = extracolor / NUMHOURS + EXTRASTART;
	CTimeCycle::m_ExtraColour = extracolor % NUMHOURS;
	CTimeCycle::m_bExtraColourOn = 1;
	CTimeCycle::m_ExtraColourInter = 0.0f;
	if(!keepInter)
		CTimeCycle::m_ExtraColourInter = 1.0f;
}

void
CTimeCycle::CopyWeather(int dst, int src)
{
	int h;
	for(h = 0; h < NUMHOURS; h++){
		m_nDirectionalMult[h][dst] = m_nDirectionalMult[h][src];
		m_nWaterFogAlpha[h][dst] = m_nWaterFogAlpha[h][src];
		m_nHighLightMinIntensity[h][dst] = m_nHighLightMinIntensity[h][src];
		m_fCloudAlpha[h][dst] = m_fCloudAlpha[h][src];
		m_fPostFx2Alpha[h][dst] = m_fPostFx2Alpha[h][src];
		m_fPostFx2Blue[h][dst] = m_fPostFx2Blue[h][src];
		m_fPostFx2Green[h][dst] = m_fPostFx2Green[h][src];
		m_fPostFx2Red[h][dst] = m_fPostFx2Red[h][src];
		m_fPostFx1Alpha[h][dst] = m_fPostFx1Alpha[h][src];
		m_fPostFx1Blue[h][dst] = m_fPostFx1Blue[h][src];
		m_fPostFx1Green[h][dst] = m_fPostFx1Green[h][src];
		m_fPostFx1Red[h][dst] = m_fPostFx1Red[h][src];
		m_fWaterAlpha[h][dst] = m_fWaterAlpha[h][src];
		m_fWaterBlue[h][dst] = m_fWaterBlue[h][src];
		m_fWaterGreen[h][dst] = m_fWaterGreen[h][src];
		m_fWaterRed[h][dst] = m_fWaterRed[h][src];
		m_nFluffyCloudsBottomRed[h][dst] = m_nFluffyCloudsBottomRed[h][src];
		m_nFluffyCloudsBottomGreen[h][dst] = m_nFluffyCloudsBottomGreen[h][src];
		m_nFluffyCloudsBottomBlue[h][dst] = m_nFluffyCloudsBottomBlue[h][src];
		m_nLowCloudsBlue[h][dst] = m_nLowCloudsBlue[h][src];
		m_nLowCloudsGreen[h][dst] = m_nLowCloudsGreen[h][src];
		m_nLowCloudsRed[h][dst] = m_nLowCloudsRed[h][src];
		m_fLightsOnGroundBrightness[h][dst] = m_fLightsOnGroundBrightness[h][src];
		m_fFogStart[h][dst] = m_fFogStart[h][src];
		m_fFarClip[h][dst] = m_fFarClip[h][src];
		m_nPoleShadowStrength[h][dst] = m_nPoleShadowStrength[h][src];
		m_nLightShadowStrength[h][dst] = m_nLightShadowStrength[h][src];
		m_nShadowStrength[h][dst] = m_nShadowStrength[h][src];
		m_fSpriteBrightness[h][dst] = m_fSpriteBrightness[h][src];
		m_fSpriteSize[h][dst] = m_fSpriteSize[h][src];
		m_fSunSize[h][dst] = m_fSunSize[h][src];
		m_nSunCoronaBlue[h][dst] = m_nSunCoronaBlue[h][src];
		m_nSunCoronaGreen[h][dst] = m_nSunCoronaGreen[h][src];
		m_nSunCoronaRed[h][dst] = m_nSunCoronaRed[h][src];
		m_nSunCoreBlue[h][dst] = m_nSunCoreBlue[h][src];
		m_nSunCoreGreen[h][dst] = m_nSunCoreGreen[h][src];
		m_nSunCoreRed[h][dst] = m_nSunCoreRed[h][src];
		m_nSkyBottomBlue[h][dst] = m_nSkyBottomBlue[h][src];
		m_nSkyBottomGreen[h][dst] = m_nSkyBottomGreen[h][src];
		m_nSkyBottomRed[h][dst] = m_nSkyBottomRed[h][src];
		m_nSkyTopBlue[h][dst] = m_nSkyTopBlue[h][src];
		m_nSkyTopGreen[h][dst] = m_nSkyTopGreen[h][src];
		m_nSkyTopRed[h][dst] = m_nSkyTopRed[h][src];
		m_nAmbientBlue_Obj[h][dst] = m_nAmbientBlue_Obj[h][src];
		m_nAmbientGreen_Obj[h][dst] = m_nAmbientGreen_Obj[h][src];
		m_nAmbientRed_Obj[h][dst] = m_nAmbientRed_Obj[h][src];
		m_nAmbientBlue[h][dst] = m_nAmbientBlue[h][src];
		m_nAmbientGreen[h][dst] = m_nAmbientGreen[h][src];
		m_nAmbientRed[h][dst] = m_nAmbientRed[h][src];
		m_nAmbientRed_Bl[h][dst] = m_nAmbientRed_Bl[h][src];
		m_nAmbientGreen_Bl[h][dst] = m_nAmbientGreen_Bl[h][src];
		m_nAmbientBlue_Bl[h][dst] = m_nAmbientBlue_Bl[h][src];
		m_nAmbientRed_Obj_Bl[h][dst] = m_nAmbientRed_Obj_Bl[h][src];
		m_nAmbientGreen_Obj_Bl[h][dst] = m_nAmbientGreen_Obj_Bl[h][src];
		m_nAmbientBlue_Obj_Bl[h][dst] = m_nAmbientBlue_Obj_Bl[h][src];
		m_nDirectionalRed[h][dst] = m_nDirectionalRed[h][src];
		m_nDirectionalGreen[h][dst] = m_nDirectionalGreen[h][src];
		m_nDirectionalBlue[h][dst] = m_nDirectionalBlue[h][src];
		m_nRadiosityIntensity[h][dst] = m_nRadiosityIntensity[h][src];
		m_nRadiosityLimit[h][dst] = m_nRadiosityLimit[h][src];
		m_nFluffyCloudsTopRed[h][dst] = m_nFluffyCloudsTopRed[h][src];
		m_nFluffyCloudsTopGreen[h][dst] = m_nFluffyCloudsTopGreen[h][src];
		m_nFluffyCloudsTopBlue[h][dst] = m_nFluffyCloudsTopBlue[h][src];
		m_fBlurRed[h][dst] = m_fBlurRed[h][src];
		m_fBlurGreen[h][dst] = m_fBlurGreen[h][src];
		m_fBlurBlue[h][dst] = m_fBlurBlue[h][src];
		m_fBlurAlpha[h][dst] = m_fBlurAlpha[h][src];
		m_fBlurOffset[h][dst] = m_fBlurOffset[h][src];
	}
}

static Reversed Initialise_kill(0x5BBAC0 + 5, 0x5BC08F);
void
CTimeCycle::Initialise(bool unused)
{
	FILE *fd;
	int w, ww, h;
	const char *line;

	int ambr, ambg, ambb;
	int ambobjr, ambobjg, ambobjb;
	int ambr_bl, ambg_bl, ambb_bl;
	int ambobjr_bl, ambobjg_bl, ambobjb_bl;
	int dirr, dirg, dirb;
	int skytopr, skytopg, skytopb;
	int skybotr, skybotg, skybotb;
	int suncorer, suncoreg, suncoreb;
	int suncoronar, suncoronag, suncoronab;
	float sunsz, sprsz, sprbght;
	int shdw, lightshd, poleshd;
	float farclp, fogst;
	int radIntensity, radLimit;
	float lightonground;
	int lowcloudr, lowcloudg, lowcloudb;
	int topcloudr, topcloudg, topcloudb;
	int bottomcloudr, bottomcloudg, bottomcloudb;
	int blurr, blurg, blurb;
	float waterr, waterg, waterb, watera;
	float blura, bluroff;

//	CFileMgr::SetDir("DATA");	// path returned is relative to root
	fd = CFileMgr::OpenFile(CFileLoader::GetTimecycPath(), "rb");
//	CFileMgr::SetDir("");

	for(ww = 0; ww < 8; ww++){
		w = CWeather::weatherMap[ww];
		for(h = 0; h < 24; h++){
			while(line = CFileLoader::LoadLine(fd), line)
				if(line[0] != '/' && line[0] != '\0')
					break;
			sscanf(line, "%d %d %d" " %d %d %d" "%d %d %d" " %d %d %d"	// Amb
				" %d %d %d"	// Dir
				" %d %d %d" " %d %d %d" // Sky top; bot
				" %d %d %d" " %d %d %d"	// Sun core; corona
				" %f %f %f"
				" %d %d %d"
				" %f %f"
				" %d %d"
				" %f"
				" %d %d %d" // low clouds
				" %d %d %d" " %d %d %d" // fluffy clouds top; bottom
				" %d %d %d"	// blur
				" %f %f %f %f"	// water
				" %f %f",	// blur alpha; offset
				&ambr, &ambg, &ambb,
				&ambobjr, &ambobjg, &ambobjb,
				&ambr_bl, &ambg_bl, &ambb_bl,
				&ambobjr_bl, &ambobjg_bl, &ambobjb_bl,
				&dirr, &dirg, &dirb,
				&skytopr, &skytopg, &skytopb,
				&skybotr, &skybotg, &skybotb,
				&suncorer, &suncoreg, &suncoreb,
				&suncoronar, &suncoronag, &suncoronab,
				&sunsz, &sprsz, &sprbght,
				&shdw, &lightshd, &poleshd,
				&farclp, &fogst,
				&radIntensity, &radLimit,
				&lightonground,
				&lowcloudr, &lowcloudg, &lowcloudb,
				&topcloudr, &topcloudg, &topcloudb,
				&bottomcloudr, &bottomcloudg, &bottomcloudb,
				&blurr, &blurg, &blurb,
				&waterr, &waterg, &waterb, &watera,
				&blura, &bluroff);
			m_nAmbientRed[h][w] = ambr;
			m_nAmbientGreen[h][w] = ambg;
			m_nAmbientBlue[h][w] = ambb;
			m_nAmbientRed_Obj[h][w] = ambobjr;
			m_nAmbientGreen_Obj[h][w] = ambobjg;
			m_nAmbientBlue_Obj[h][w] = ambobjb;
			m_nAmbientRed_Bl[h][w] = ambr_bl;
			m_nAmbientGreen_Bl[h][w] = ambg_bl;
			m_nAmbientBlue_Bl[h][w] = ambb_bl;
			m_nAmbientRed_Obj_Bl[h][w] = ambobjr_bl;
			m_nAmbientGreen_Obj_Bl[h][w] = ambobjg_bl;
			m_nAmbientBlue_Obj_Bl[h][w] = ambobjb_bl;
			m_nDirectionalRed[h][w] = dirr;
			m_nDirectionalGreen[h][w] = dirg;
			m_nDirectionalBlue[h][w] = dirb;
			m_nSkyTopRed[h][w] = skytopr;
			m_nSkyTopGreen[h][w] = skytopg;
			m_nSkyTopBlue[h][w] = skytopb;
			m_nSkyBottomRed[h][w] = skybotr;
			m_nSkyBottomGreen[h][w] = skybotg;
			m_nSkyBottomBlue[h][w] = skybotb;
			m_nSunCoreRed[h][w] = suncorer;
			m_nSunCoreGreen[h][w] = suncoreg;
			m_nSunCoreBlue[h][w] = suncoreb;
			m_nSunCoronaRed[h][w] = suncoronar;
			m_nSunCoronaGreen[h][w] = suncoronag;
			m_nSunCoronaBlue[h][w] = suncoronab;
			m_fSunSize[h][w] = sunsz*10.0f + 0.5f;
			m_fSpriteSize[h][w] = sprsz*10.0f + 0.5f;
//			m_fSpriteBrightness[h][w] = sprbght*10.0f + 0.5f;
			// HACK: SA can't handle values above 1.0; do something that doesn't look exceptionally crappy
			m_fSpriteBrightness[h][w] = sprbght*2;
			if(m_fSpriteBrightness[h][w] > 10) m_fSpriteBrightness[h][w] = 10;
			m_nShadowStrength[h][w] = shdw;
			m_nLightShadowStrength[h][w] = lightshd;
			m_nPoleShadowStrength[h][w] = poleshd;
			m_fFarClip[h][w] = farclp;
			m_fFogStart[h][w] = fogst;
			m_nRadiosityIntensity[h][w] = radIntensity;
			m_nRadiosityLimit[h][w] = radLimit,
			m_fLightsOnGroundBrightness[h][w] = lightonground*10.0f + 0.5f;
			m_nLowCloudsRed[h][w] = lowcloudr;
			m_nLowCloudsGreen[h][w] = lowcloudg;
			m_nLowCloudsBlue[h][w] = lowcloudb;
			m_nFluffyCloudsBottomRed[h][w] = bottomcloudr;
			m_nFluffyCloudsBottomGreen[h][w] = bottomcloudg;
			m_nFluffyCloudsBottomBlue[h][w] = bottomcloudb;
			m_nFluffyCloudsTopRed[h][w] = topcloudr;
			m_nFluffyCloudsTopGreen[h][w] = topcloudg;
			m_nFluffyCloudsTopBlue[h][w] = topcloudb;
			m_fBlurRed[h][w] = blurr;
			m_fBlurGreen[h][w] = blurg;
			m_fBlurBlue[h][w] = blurb;
			m_fWaterRed[h][w] = waterr;
			m_fWaterGreen[h][w] = waterg;
			m_fWaterBlue[h][w] = waterb;
			m_fWaterAlpha[h][w] = watera;
			m_fBlurAlpha[h][w] = blura;
			m_fBlurOffset[h][w] = bluroff;
		}
	}
	CFileMgr::CloseFile(fd);

	// fill unused slots with similar data
	for(w = 0; w < NUMWEATHERS; w++)
		CopyWeather(w, CWeather::weatherMap[CWeather::revWeatherMap[w]]);

	float c = cos(0.7853981852531433);
	m_vecDirnLightToSun.x = cos(-2.356194496154785) * c;
	m_vecDirnLightToSun.y = sin(-2.356194496154785) * c;
	m_vecDirnLightToSun.z = sin(0.7853981852531433);
	m_vecDirnLightToSun.Normalise();
	m_FogReduction = 0;
	m_bExtraColourOn = 0;
}

WRAPPER void CTimeCycle::FindTimeCycleBox(float x, float y, float z, CTimeCycleBox **box, float *interp, bool checkLod, bool checkFar, CTimeCycleBox *exclude)
{ WRAPARG(x); WRAPARG(y); WRAPARG(z); WRAPARG(box); WRAPARG(interp); WRAPARG(checkLod); WRAPARG(checkFar); WRAPARG(exclude); EAXJMP(0x55FFD0); }

static uint8 timecycleHours[25] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24 };
static uint8 timecycleHorizon[24] = { 30, 30, 30, 30, 30, 30, 30, 50, 52, 54, 56, 58, 60, 60, 60, 60, 60, 60, 60, 60, 50, 42, 35, 32 };
int &tunnelWeather = *(int*)0x8CDEE0;

static Reversed CalcColoursForPoint_kill(0x5603D0, 0x5616DF);
void
CTimeCycle::CalcColoursForPoint(float x, float y, float z, CColourSet *colorset)
{
	CTimeCycleBox *lodBox, *farBox1, *farBox2, *weatherBox, *tmpBox;
	float lodBoxInterp, farBox1Interp, farBox2Interp, weatherBoxInterp, tmpInterp;
	float time;
	int curHourSel, nextHourSel;
	int curHour, nextHour;
	float timeInterp, invTimeInterp, weatherInterp, invWeatherInterp;
	int boxWeather, boxHour;
	float lightMult;
	float sunAngle;
	CVector *vec;
	float inc;
	float camZ;
	float horiz;
	float f;

	FindTimeCycleBox(x, y, z, &lodBox, &lodBoxInterp, true, false, NULL);
	FindTimeCycleBox(x, y, z, &farBox1, &farBox1Interp, false, true, NULL);
	if(farBox1){
		CTimeCycle::FindTimeCycleBox(x, y, z, &farBox2, &farBox2Interp, false, true, farBox1);
		if(farBox2)
		if(farBox2->box.max.x - farBox2->box.min.x > farBox1->box.max.x - farBox1->box.min.x){
			tmpBox = farBox1;
			farBox1 = farBox2;
			farBox2 = tmpBox;
			tmpInterp = farBox2Interp;
			farBox2Interp = farBox1Interp;
			farBox1Interp = tmpInterp;
		}
	}else
		farBox2 = NULL;
	FindTimeCycleBox(x, y, z, &weatherBox, &weatherBoxInterp, false, false, NULL);

	time = CClock::GetHours()
	     + CClock::GetMinutes() / 60.0f
	     + CClock::GetSeconds() / 3600.0f;
	if(time >= 23.999f)
		time = 23.999f;

	for(curHourSel = 0; time >= timecycleHours[curHourSel+1]; curHourSel++);
	nextHourSel = (curHourSel + 1) % NUMHOURS;
	curHour = timecycleHours[curHourSel];
	nextHour = timecycleHours[curHourSel+1];
	timeInterp = (time - curHour) / (float)(nextHour - curHour);
	invTimeInterp = 1.0f - timeInterp;
	weatherInterp = CWeather::InterpolationValue;
	invWeatherInterp = 1.0f - weatherInterp;
	if(weatherBox){
		boxWeather = (weatherBox->extraColor / NUMHOURS) + EXTRASTART;
		boxHour = weatherBox->extraColor % NUMHOURS;
	}
	CColourSet curold(curHourSel, CWeather::OldWeatherType);
	CColourSet nextold(nextHourSel, CWeather::OldWeatherType);
	CColourSet curnew(curHourSel, CWeather::NewWeatherType);
	CColourSet nextnew(nextHourSel, CWeather::NewWeatherType);

	camZ = TheCamera.GetCoords().z;

	CColourSet oldInterp, newInterp;
	oldInterp.Interpolate(&curold, &nextold, invTimeInterp, timeInterp, false);
	newInterp.Interpolate(&curnew, &nextnew, invTimeInterp, timeInterp, false);
	colorset->Interpolate(&oldInterp, &newInterp, invWeatherInterp, weatherInterp, false);

	lightMult = (1.0f / CCoronas::LightsMult + 3.0f) * 0.25f;
	colorset->skytopr *= lightMult;
	colorset->skytopg *= lightMult;
	colorset->skytopb *= lightMult;
	colorset->skybotr *= lightMult;
	colorset->skybotg *= lightMult;
	colorset->skybotb *= lightMult;
	if(colorset->skytopr > 0xFF) colorset->skytopr = 0xFF;
	if(colorset->skytopg > 0xFF) colorset->skytopg = 0xFF;
	if(colorset->skytopb > 0xFF) colorset->skytopb = 0xFF;
	if(colorset->skybotr > 0xFF) colorset->skybotr = 0xFF;
	if(colorset->skybotg > 0xFF) colorset->skybotg = 0xFF;
	if(colorset->skybotb > 0xFF) colorset->skybotb = 0xFF;

	if(m_FogReduction)
		colorset->farclp = colorset->farclp > m_FogReduction*10.15625 ? colorset->farclp : m_FogReduction*10.15625;

	m_CurrentStoredValue = (m_CurrentStoredValue + 1) & 0xF;
	vec = &m_VectorToSun[m_CurrentStoredValue];
	sunAngle = (CClock::GetHours()*60.0 + CClock::GetMinutes() + CClock::GetSeconds()/60.0) * 0.0043633231;
	vec->x = sin(sunAngle);
	vec->y = 1.0;
	vec->z = 0.2 - cos(sunAngle);
	vec->Normalise();

	if(weatherBox && weatherBox->extraColor >= 0){
		float boxf = weatherBoxInterp * weatherBox->strength;
		float invboxf = 1.0 - boxf;

		colorset->skytopr = colorset->skytopr*invboxf + m_nSkyTopRed[boxHour][boxWeather]*boxf;
		colorset->skytopg = colorset->skytopg*invboxf + m_nSkyTopGreen[boxHour][boxWeather]*boxf;
		colorset->skytopb = colorset->skytopg*invboxf + m_nSkyTopBlue[boxHour][boxWeather]*boxf;

		colorset->skybotr = colorset->skybotr*invboxf + m_nSkyBottomRed[boxHour][boxWeather]*boxf;
		colorset->skybotg = colorset->skybotg*invboxf + m_nSkyBottomGreen[boxHour][boxWeather]*boxf;
		colorset->skybotb = colorset->skybotb*invboxf + m_nSkyBottomBlue[boxHour][boxWeather]*boxf;

		colorset->waterr = colorset->waterr*invboxf + m_fWaterRed[boxHour][boxWeather]*boxf;
		colorset->waterg = colorset->waterg*invboxf + m_fWaterGreen[boxHour][boxWeather]*boxf;
		colorset->waterb = colorset->waterb*invboxf + m_fWaterBlue[boxHour][boxWeather]*boxf;
		colorset->watera = colorset->watera*invboxf + m_fWaterAlpha[boxHour][boxWeather]*boxf;

		colorset->ambr = colorset->ambr*invboxf + m_nAmbientRed[boxHour][boxWeather]*boxf;
		colorset->ambg = colorset->ambg*invboxf + m_nAmbientGreen[boxHour][boxWeather]*boxf;
		colorset->ambb = colorset->ambb*invboxf + m_nAmbientBlue[boxHour][boxWeather]*boxf;

		colorset->ambobjr = colorset->ambobjr*invboxf + m_nAmbientRed_Obj[boxHour][boxWeather]*boxf;
		colorset->ambobjg = colorset->ambobjg*invboxf + m_nAmbientGreen_Obj[boxHour][boxWeather]*boxf;
		colorset->ambobjb = colorset->ambobjb*invboxf + m_nAmbientBlue_Obj[boxHour][boxWeather]*boxf;

		if(m_fFarClip[boxHour][boxWeather] < colorset->farclp)
			colorset->farclp = colorset->farclp*invboxf + m_fFarClip[boxHour][boxWeather]*boxf;

		colorset->fogst = colorset->fogst*invboxf + m_fFogStart[boxHour][boxWeather]*boxf;

		colorset->postfx1r = colorset->postfx1r*invboxf + m_fPostFx1Red[boxHour][boxWeather]*boxf;
		colorset->postfx1g = colorset->postfx1g*invboxf + m_fPostFx1Green[boxHour][boxWeather]*boxf;
		colorset->postfx1b = colorset->postfx1b*invboxf + m_fPostFx1Blue[boxHour][boxWeather]*boxf;
		colorset->postfx1a = colorset->postfx1a*invboxf + m_fPostFx1Alpha[boxHour][boxWeather]*boxf;

		colorset->postfx2r = colorset->postfx2r*invboxf + m_fPostFx2Red[boxHour][boxWeather]*boxf;
		colorset->postfx2g = colorset->postfx2g*invboxf + m_fPostFx2Green[boxHour][boxWeather]*boxf;
		colorset->postfx2b = colorset->postfx2b*invboxf + m_fPostFx2Blue[boxHour][boxWeather]*boxf;
		colorset->postfx2a = colorset->postfx2a*invboxf + m_fPostFx2Alpha[boxHour][boxWeather]*boxf;
	}

	if(lodBox)
		colorset->lodDistMult = colorset->lodDistMult*(1.0f-lodBoxInterp) + lodBox->lodDistMult/32.0f*lodBoxInterp;

	if(farBox1 && farBox1->farclp < colorset->farclp)
		colorset->farclp = colorset->farclp*(1.0f-farBox1Interp) + farBox1->farclp*farBox1Interp;
	if(farBox2 && farBox2->farclp < colorset->farclp)
		colorset->farclp = colorset->farclp*(1.0f-farBox2Interp) + farBox2->farclp*farBox2Interp;

	inc = CTimer::ms_fTimeStep/120.0f;
	if(m_bExtraColourOn){
		m_ExtraColourInter += inc;
		if(m_ExtraColourInter > 1.0f)
			m_ExtraColourInter = 1.0f;
	}else{
		m_ExtraColourInter -= inc;
		if(m_ExtraColourInter < 0.0f)
			m_ExtraColourInter = 0.0f;
	}
	if(m_ExtraColourInter > 0.0f){
		CColourSet extraset(m_ExtraColour, m_ExtraColourWeatherType);
		colorset->Interpolate(colorset, &extraset, 1.0f-m_ExtraColourInter, m_ExtraColourInter, 
			m_nSkyTopRed[m_ExtraColour][m_ExtraColourWeatherType] == 0 && 
			m_nSkyTopGreen[m_ExtraColour][m_ExtraColourWeatherType] == 0 && 
			m_nSkyTopBlue[m_ExtraColour][m_ExtraColourWeatherType] == 0);
	}

	if(CWeather::UnderWaterness > 0.0f){
		CColourSet curuwset(curHourSel, 20);
		CColourSet nextuwset(nextHourSel, 20);
		CColourSet tmpset;
		tmpset.Interpolate(&curuwset, &nextuwset, invTimeInterp, timeInterp, false);
		colorset->Interpolate(colorset, &tmpset, 1.0f-CWeather::UnderWaterness, CWeather::UnderWaterness, false);
	}

	if(CWeather::InTunnelness > 0.0f){
		CColourSet tunnelset(tunnelWeather % NUMHOURS, tunnelWeather / NUMHOURS + EXTRASTART);
		colorset->Interpolate(colorset, &tunnelset, 1.0f-CWeather::InTunnelness, CWeather::InTunnelness, 
			m_nSkyTopRed[m_ExtraColour][m_ExtraColourWeatherType] == 0 && 
			m_nSkyTopGreen[m_ExtraColour][m_ExtraColourWeatherType] == 0 && 
			m_nSkyTopBlue[m_ExtraColour][m_ExtraColourWeatherType] == 0);
	}

	colorset->ambr /= 255;
	colorset->ambg /= 255;
	colorset->ambb /= 255;
	colorset->ambobjr /= 255;
	colorset->ambobjg /= 255;
	colorset->ambobjb /= 255;
	colorset->vertmultr /= 255;
	colorset->vertmultg /= 255;
	colorset->vertmultb /= 255;
	colorset->dirr /= 255;
	colorset->dirg /= 255;
	colorset->dirb /= 255;

	CShadows::CalcPedShadowValues(
		m_VectorToSun[m_CurrentStoredValue].x,
		m_VectorToSun[m_CurrentStoredValue].y,
		m_VectorToSun[m_CurrentStoredValue].z,
		&m_fShadowFrontX[m_CurrentStoredValue],
		&m_fShadowFrontY[m_CurrentStoredValue],
		&m_fShadowSideX[m_CurrentStoredValue],
		&m_fShadowSideY[m_CurrentStoredValue],
		&m_fShadowDisplacementX[m_CurrentStoredValue],
		&m_fShadowDisplacementY[m_CurrentStoredValue]);

	if(((CMatrix*)((char*)&TheCamera + 0x974))->matrix.up.z < -0.9
		|| !CWeather::bScriptsForceRain
		&& (CCullZones::PlayerNoRain() || CCullZones::CamNoRain() || CCutsceneMgr::ms_running)){
		m_FogReduction++;
		if(m_FogReduction > 64)
			m_FogReduction = 64;
	}else{
		m_FogReduction--;
		if(m_FogReduction < 0)
			m_FogReduction = 0;
	}

	if(camZ > 200.0f){
		if(camZ <= 500.0f)
			colorset->farclp = colorset->farclp*(1.0f - (camZ-200.0f)/300.0f) + 1000.0f*(camZ-200.0f)/300.0f;
		else if(colorset->farclp >= 1000.0f)
			colorset->farclp = 1000.0f;
	}

	horiz = timecycleHorizon[curHourSel]*invTimeInterp + timecycleHorizon[nextHourSel]*timeInterp;
	m_BelowHorizonGrey.red = m_CurrentColours.skybotr*CWeather::UnderWaterness + horiz*(1.0f - CWeather::UnderWaterness);
	m_BelowHorizonGrey.green = m_CurrentColours.skybotg*CWeather::UnderWaterness + horiz*(1.0f - CWeather::UnderWaterness);
	m_BelowHorizonGrey.blue = m_CurrentColours.skybotb*CWeather::UnderWaterness + horiz*(1.0f - CWeather::UnderWaterness);

	colorset->ambBeforeBrightnessr = colorset->ambr;
	colorset->ambBeforeBrightnessg = colorset->ambg;
	colorset->ambBeforeBrightnessb = colorset->ambb;
	m_BrightnessAddedToAmbientRed = 0.0;
	m_BrightnessAddedToAmbientGreen = 0.0;
	m_BrightnessAddedToAmbientBlue = 0.0;

	f = 0.0;
	if(x < -3000.0)
		f = -(x + 3000.0);
	else if(x > 3000.0)
		f = x - 3000.0;
	if(y < -3000.0)
		f += -(y + 3000.0);
	else if(y > 3000.0)
		f += y - 3000.0;
	if(f >= 1000.0)
		colorset->lodDistMult *= 2.0;
	else if(f > 0.0)
		colorset->lodDistMult = (f/1000.0 + 1.0) * colorset->lodDistMult;

	colorset->convertToSA();
}

static Reversed FindFarClipForCoors_kill(0x5616E0 + 5, 0x56175F);
double
CTimeCycle::FindFarClipForCoors(float x, float y, float z)
{
	CColourSet s;
	bool extraOn;
	float extraInter;
	extraOn = CTimeCycle::m_bExtraColourOn != 0;
	extraInter = CTimeCycle::m_ExtraColourInter;
	CTimeCycle::m_bExtraColourOn = 0;
	CTimeCycle::m_ExtraColourInter = 0.0;
	CTimeCycle::CalcColoursForPoint(x, y, z, &s);
	CTimeCycle::m_bExtraColourOn = extraOn;
	CTimeCycle::m_ExtraColourInter = extraInter;
	return s.farclp;
}

static Reversed Update_kill(0x561760, 0x56179F);
void
CTimeCycle::Update(void)
{
	CVector &pos = TheCamera.GetCoords();
	CalcColoursForPoint(pos.x, pos.y, pos.z, &m_CurrentColours);
	memcpy(&m_CurrentColours_exe, &m_CurrentColours, 0xAC);
}

static StaticPatcher	Patcher([]()
{
	Memory::InjectHook(0x55FEC0, CTimeCycle::StartExtraColour, PATCH_JUMP);

	Memory::InjectHook(0x5BBAC0, CTimeCycle::Initialise, PATCH_JUMP);
	// Memory::InjectHook(0x55F4B0, &CColourSet::ctor, PATCH_JUMP);
	// Memory::InjectHook(0x55F870, &CColourSet::Interpolate, PATCH_JUMP);
	// Memory::InjectHook(0x5603D0, CTimeCycle::CalcColoursForPoint, PATCH_JUMP);
	Memory::InjectHook(0x5616E0, CTimeCycle::FindFarClipForCoors, PATCH_JUMP);
	// Memory::InjectHook(0x561760, CTimeCycle::Update, PATCH_JUMP);

	Memory::InjectHook(0x72B916, CWeather::FindWeatherTypesList);
	Memory::InjectHook(0x72A640, CWeather::UpdateWeatherRegion, PATCH_JUMP);

	if(DebugMenuLoad()){
		// this is a bit ugly because we're reusing the SA weathers :/
		static const char *weathers[] = {
			"*Extrasunny", "*Sunny", "*Extrasunny", "*Sunny", "*Cloudy",
			"Sunny", "Extrasunny", "Cloudy", "Rainy", "Foggy",
			"*Sunny", "*Extrasunny", "*Cloudy",
			"Ultrasunny", "*Sunny", "*Cloudy", "Hurricane",
			"*Extrasunny", "*Sunny", "*Hurricane",
			"*Sunny",  
		};

		DebugMenuEntry *e;
		e = DebugMenuAddVar("Time & Weather", "Current Hour", &CClock::ms_nGameClockHours, NULL, 1, 0, 23, NULL);
		DebugMenuEntrySetWrap(e, true);
		e = DebugMenuAddVar("Time & Weather", "Current Minute", &CClock::ms_nGameClockMinutes,
			[](){ CWeather::InterpolationValue = CClock::ms_nGameClockMinutes/60.0f + CClock::ms_nGameClockSeconds/3600.0f; }, 1, 0, 59, NULL);
		DebugMenuEntrySetWrap(e, true);
		e = DebugMenuAddVar("Time & Weather", "Old Weather", &CWeather::OldWeatherType, NULL, 1, 0, 20, weathers);
		DebugMenuEntrySetWrap(e, true);
		e = DebugMenuAddVar("Time & Weather", "New Weather", &CWeather::NewWeatherType, NULL, 1, 0, 20, weathers);
		DebugMenuEntrySetWrap(e, true);
		DebugMenuAddVar("Time & Weather", "Time scale", &CTimer::ms_fTimeScale, NULL, 0.1f, 0.0f, 10.0f);
	}
});
