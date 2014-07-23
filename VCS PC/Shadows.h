#ifndef __SHADOWS
#define __SHADOWS

enum eShadowQuality
{
	SHADOW_QUALITY_OFF,
	SHADOW_QUALITY_LOWEST,
	SHADOW_QUALITY_LOW,
	SHADOW_QUALITY_MEDIUM,
	SHADOW_QUALITY_HIGH,
	SHADOW_QUALITY_HIGHEST
};

class CShadows
{
private:
	// VCS PC class extension
	static eShadowQuality			m_bShadowQuality;

public:
	static void						RenderIndicatorShadow(unsigned int nIndex, unsigned char, RwTexture*, CVector* pPos, float radiusX, float, float, float radiusY, short);

	static inline void				SetShadowQuality(eShadowQuality nQuality)
		{ m_bShadowQuality = nQuality; }
	static inline eShadowQuality	GetShadowQuality()
		{ return m_bShadowQuality; }

	static void						InitialiseChangedSettings();
	static void						Inject();
};

#endif