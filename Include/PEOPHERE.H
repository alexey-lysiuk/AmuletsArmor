/****************************************************************************/
/*    FILE:  PEOPHERE.H                                                     */
/****************************************************************************/
#ifndef _PEOPHERE_H_
#define _PEOPHERE_H_

#include "GENERAL.H"
#include "SERVER.H"
#include "CMDQUEUE.H"

// Routines to setup:
T_void PeopleHereInitialize(T_void) ;
T_void PeopleHereFinish(T_void) ;
T_void PeopleHereReset(T_void) ;

// Routines for updating other individual player info:
T_void PeopleHereUpdatePlayer(T_playerIDSelf *p_playerID) ;
T_void PeopleHereGetPlayerIDSelfStruct(T_playerIDSelf *p_self) ;
T_gameGroupID PeopleHereGetUniqueGroupID(T_void) ;

// Routines for seeking info about players
T_void PeopleHereIDPlayer(T_word16 playerNum, T_byte8 *p_name) ;
T_void PeopleHereResetPlayerIDs(T_void) ;
T_byte8 *PeopleHereGetPlayerIDName(T_word16 playerNum) ;

// Routines to update our own state
T_void PeopleHereSetOurState(T_playerIDState state) ;
T_playerIDState PeopleHereGetOurState(T_void) ;
T_playerIDLocation PeopleHereGetOurLocation(T_void) ;
T_void PeopleHereSetOurAdventure(T_word16 adventure) ;
T_word16 PeopleHereGetOurAdventure(T_void) ;

// Routines for handling a game about to start
T_void PeopleHereGeneratePeopleInGame(T_gameGroupID groupID) ;
T_void PeopleHereStartGame(T_word16 firstLevel) ;
T_word16 PeopleHereGetNumInGroupGame(void);

// Routines for communications:
T_directTalkUniqueAddress *PeopleHereGetUniqueAddr(T_word16 playerNum) ;
T_void PeopleHereSetUniqueAddr(
           T_word16 playerNum,
           T_directTalkUniqueAddress *uaddr) ;
T_void PeopleHereRequestJoin(
        T_directTalkUniqueAddress uniqueAddress,
        T_gameGroupID groupID,
        T_word16 adventure) ;
T_void PeopleHereRespondToJoin(
       T_directTalkUniqueAddress uniqueAddress,
       T_gameGroupID groupID,
       T_word16 adventure,
       E_respondJoin response);
T_void PeopleHereSendPacketToGroup(
        T_gameGroupID groupID,
        T_packetLong *p_packet,
        T_word16 retryTime,
        T_word32 extraData,
        T_cmdQPacketCallback p_callback);

#endif

/****************************************************************************/
/*    END OF FILE:  PEOPHERE.H                                              */
/****************************************************************************/
