#include "switch_defs.h"
#include "hud.h"
#include "cl_util.h"
#include "netadr.h"
#include "parsemsg.h"

extern "C"
{
int DLLEXPORT Initialize( cl_enginefunc_t *pEnginefuncs, int iVersion );
int DLLEXPORT HUD_VidInit( void );
void DLLEXPORT HUD_Init( void );
int DLLEXPORT HUD_Redraw( float flTime, int intermission );
int DLLEXPORT HUD_UpdateClientData( client_data_t *cdata, float flTime );
void DLLEXPORT HUD_Reset ( void );
void DLLEXPORT HUD_PlayerMove( struct playermove_s *ppmove, int server );
void DLLEXPORT HUD_PlayerMoveInit( struct playermove_s *ppmove );
char DLLEXPORT HUD_PlayerMoveTexture( char *name );
int DLLEXPORT HUD_ConnectionlessPacket( const struct netadr_s *net_from, const char *args, char *response_buffer, int *response_buffer_size );
int DLLEXPORT HUD_GetHullBounds( int hullnumber, float *mins, float *maxs );
void DLLEXPORT HUD_Frame( double time );
void DLLEXPORT HUD_VoiceStatus(int entindex, qboolean bTalking);
void DLLEXPORT HUD_DirectorMessage( int iSize, void *pbuf );
int DLLEXPORT HUD_MobilityInterface( mobile_engfuncs_t *mobileapi );
void DLLEXPORT HUD_Shutdown( void );
void DLLEXPORT HUD_PostRunCmd( struct local_state_s *from, struct local_state_s *to, struct usercmd_s *cmd, int runfuncs, double time, unsigned int random_seed );
int DLLEXPORT HUD_Key_Event( int down, int keynum, const char *pszCurrentBinding );
int DLLEXPORT HUD_AddEntity( int type, struct cl_entity_s *ent, const char *modelname );
void DLLEXPORT HUD_CreateEntities( void );
void DLLEXPORT HUD_StudioEvent( const struct mstudioevent_s *event, const struct cl_entity_s *entity );
void DLLEXPORT HUD_TxferLocalOverrides( struct entity_state_s *state, const struct clientdata_s *client );
void DLLEXPORT HUD_ProcessPlayerState( struct entity_state_s *dst, const struct entity_state_s *src );
void DLLEXPORT HUD_TxferPredictionData ( struct entity_state_s *ps, const struct entity_state_s *pps, struct clientdata_s *pcd, const struct clientdata_s *ppcd, struct weapon_data_s *wd, const struct weapon_data_s *pwd );
void DLLEXPORT HUD_TempEntUpdate( double frametime, double client_time, double cl_gravity, struct tempent_s **ppTempEntFree, struct tempent_s **ppTempEntActive, int ( *Callback_AddVisibleEntity )( struct cl_entity_s *pEntity ), void ( *Callback_TempEntPlaySound )( struct tempent_s *pTemp, float damp ) );
int DLLEXPORT HUD_GetStudioModelInterface( int version, struct r_studio_interface_s **ppinterface, struct engine_studio_api_s *pstudio );
void DLLEXPORT HUD_DrawNormalTriangles( void );
void DLLEXPORT HUD_DrawTransparentTriangles( void );
cl_entity_t DLLEXPORT *HUD_GetUserEntity( int index );
void DLLEXPORT Demo_ReadBuffer( int size, unsigned char *buffer );
void DLLEXPORT CL_CreateMove( float frametime, struct usercmd_s *cmd, int active );
struct kbutton_s DLLEXPORT *KB_Find( const char *name );
void DLLEXPORT CAM_Think( void );
int DLLEXPORT CL_IsThirdPerson( void );
void DLLEXPORT CL_CameraOffset( float *ofs );
void DLLEXPORT IN_ClientMoveEvent( float forwardmove, float sidemove );
void DLLEXPORT IN_ClientLookEvent( float relyaw, float relpitch );
void DLLEXPORT IN_MouseEvent_CL( int mstate );
void DLLEXPORT IN_ClearStates( void );
void DLLEXPORT IN_ActivateMouse_CL( void );
void DLLEXPORT IN_DeactivateMouse_CL( void );
void DLLEXPORT IN_Accumulate( void );
void DLLEXPORT V_CalcRefdef_CL( struct ref_params_s *pparams );

dllexport_t switch_client_exports[] = {
	{ "Initialize", (void*)Initialize },
	{ "HUD_VidInit", (void*)HUD_VidInit },
	{ "HUD_Init", (void*)HUD_Init },
	{ "HUD_Shutdown", (void*)HUD_Shutdown },
	{ "HUD_Redraw", (void*)HUD_Redraw },
	{ "HUD_UpdateClientData", (void*)HUD_UpdateClientData },
	{ "HUD_Reset", (void*)HUD_Reset },
	{ "HUD_PlayerMove", (void*)HUD_PlayerMove },
	{ "HUD_PlayerMoveInit", (void*)HUD_PlayerMoveInit },
	{ "HUD_PlayerMoveTexture", (void*)HUD_PlayerMoveTexture },
	{ "HUD_ConnectionlessPacket", (void*)HUD_ConnectionlessPacket },
	{ "HUD_GetHullBounds", (void*)HUD_GetHullBounds },
	{ "HUD_Frame", (void*)HUD_Frame },
	{ "HUD_PostRunCmd", (void*)HUD_PostRunCmd },
	{ "HUD_Key_Event", (void*)HUD_Key_Event },
	{ "HUD_AddEntity", (void*)HUD_AddEntity },
	{ "HUD_CreateEntities", (void*)HUD_CreateEntities },
	{ "HUD_StudioEvent", (void*)HUD_StudioEvent },
	{ "HUD_TxferLocalOverrides", (void*)HUD_TxferLocalOverrides },
	{ "HUD_ProcessPlayerState", (void*)HUD_ProcessPlayerState },
	{ "HUD_TxferPredictionData", (void*)HUD_TxferPredictionData },
	{ "HUD_TempEntUpdate", (void*)HUD_TempEntUpdate },
	{ "HUD_DrawNormalTriangles", (void*)HUD_DrawNormalTriangles },
	{ "HUD_DrawTransparentTriangles", (void*)HUD_DrawTransparentTriangles },
	{ "HUD_GetUserEntity", (void*)HUD_GetUserEntity },
	{ "Demo_ReadBuffer", (void*)Demo_ReadBuffer },
	{ "CAM_Think", (void*)CAM_Think },
	{ "CL_IsThirdPerson", (void*)CL_IsThirdPerson },
	{ "CL_CameraOffset", (void*)CL_CameraOffset },
	{ "CL_CreateMove", (void*)CL_CreateMove },
	{ "IN_ActivateMouse", (void*)IN_ActivateMouse_CL },
	{ "IN_DeactivateMouse", (void*)IN_DeactivateMouse_CL },
	{ "IN_MouseEvent", (void*)IN_MouseEvent_CL },
	{ "IN_Accumulate", (void*)IN_Accumulate },
	{ "IN_ClearStates", (void*)IN_ClearStates },
	{ "V_CalcRefdef", (void*)V_CalcRefdef_CL },
	{ "KB_Find", (void*)KB_Find },
	{ "HUD_GetStudioModelInterface", (void*)HUD_GetStudioModelInterface },
	{ "HUD_DirectorMessage", (void*)HUD_DirectorMessage },
	{ "HUD_VoiceStatus", (void*)HUD_VoiceStatus },
	{ "IN_ClientMoveEvent", (void*)IN_ClientMoveEvent}, // Xash3D ext
    { "IN_ClientLookEvent", (void*)IN_ClientLookEvent}, // Xash3D ext
	{ NULL, NULL },
};

int switch_installdll_client( void )
{
	return dll_register( "client", switch_client_exports );
}

}