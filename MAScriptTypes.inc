/* 
	// For the time being we will not assign tags https://github.com/compuphase/pawn/blob/master/doc/Pawn_Language_Guide.pdf pg.65
    These .inc files follow Hungarian Notation as seen here https://www.cse.iitk.ac.in/users/dsrkg/cs245/html/Guide.htm
    String     Prefix: s Suffix: []   // Suffix required because strings are arrays of chars
    Boolean    Prefix: b
    Integer    Prefix: n
    Float      Prefix: f
    For FANG specific data types, we will use these
    Entity     Prefix: h              // Yes this is also handle in Hungarian Notation
    FVec3Obj   Prefix: vec
    FQuatObj   Prefix: q
    CFMtx43A   Prefix: mtx
    MeshEntity Prefix: hme
    MeshActor  Prefix: hma
    BTI        Prefix: hbti
    BTR        Prefix: hbtr
    AnimInst   Prefix: hai
    AudioRes   Prefix: har
    Audio      Prefix: haud
    Particle   Prefix: hp
    Bot        Prefix: hbot
    BotActor   Prefix: hact
    Door       Prefix: hd
*/

//═══════════════════════════════════════════════════════════════ Entity

native E_Find(sEntityName[]);
native E_FindInWorld(sEntityName[]);
native E_FindOutWorld(sEntityName[]);
native E_AddToWorld(hEntity);
native E_RemoveFromWorld(hEntity);

native E_IsValid(hEntity);
native E_IsNamed(hEntity, sEntityName[]);
native E_IsInWorld(hEntity);

native E_IsBot(hEntity);
native E_IsDoor(hEntity);
native E_IsMesh(hEntity);
native E_IsSwitch(hEntity);
native E_IsTripwire(hEntity);

native E_IsTargetable(hEntity);
native E_IsHittable(hEntity);
native E_IsActionable(hEntity);

native E_EnableTripwire(hEntity, bIsEnabled);

native E_GetPos(hEntity, vecPos);
native E_DistanceBetween(hEntityA, hEntityB);
native E_SnapToE(hEntityHunter, hEntityTarget);

native E_SetNormHealth(hEntity, fHealth);
native E_GetNormHealth(hEntity);
native E_SetExplodArmor(hEntity, fUnitArmor);
native E_SetFlameArmor(hEntity, fUnitArmor);
native E_SetBulletArmor(hEntity, fUnitArmor);
native E_SetTargetable(hEntity, bIsTargetable);
native E_TouchOfDeath(hEntity, bSpawnGoodies);
native E_SetDamageable(hEntity, bIsDamagable);
native E_IsDamageable(hEntity);
// @param fBlastIntensity (Default 1) >1 bigger explosion
native E_Blast(hEntity, fBlastIntensity);

//═══════════════════════════════════════════════════════════════ Bot

native Bot_Find(sBotName[]);

native Bot_IsValid(hBot);
native Bot_AddToWorld(hBot);
// Can be used to force eject Glitch from a bot regardless of how it was possessed
native Bot_RemoveFromWorld(hBot);
native Bot_IsDeadOrDying(hBot);
native Bot_IsDead(hBot);

// @param nLookAroundChance Range 0 - 100, likelyhood bot will look around
native Bot_JobWait(hBot, nLookAroundChance);
native Bot_JobWaitAndLook(hBot, hLookAtEntity, nLookAroundChance);
// This may be broken, script wants 8 but function takes 9 parameters???
native Bot_JobWander(hBot, fWonderRadius, bStayInRoom, nSpeedPctMin, nSpeedPctMax, nSociable, nCuriosity, nTakeBreakChance);
// @param nPatrolSpeed (0 - 100) % of bot's max speed
// @param nDirection   (0 or 1) Clockwise or counterclockwise respectfully
native Bot_JobPatrol(hBot, sPathName[], nPatrolSpeed, nDirection);
// @param nSpeedPercent (0 - 100) % of bot's max speed
// @param nReact        (DISABLE_AI_REACTIONS, ENABLE_AI_REACTIONS, ENABLE_ATTACK_ON_THE_WAY)
native Bot_GoalGotoPos(hBot, vecDestination, nSpeedPercent, nGoToFlags, nReact);
// @param bEventWhenDone   (True / False) Uses event type "ai"
// @param nWhenToStartLook (0 - 100) % of distance from starting to ending position to start looking at hEntityLookAt
native Bot_GotoE(hBot, hEntityDestination, bEventWhenDone, nSpeedPercent, hEntityLookAt, nWhenToStartLook);
native Bot_GotoEO(hBot, hEntityDestination, bEventWhenDone, nSpeedPercent, hEntityLookAt, nWhenToStartLook);

native Bot_Attack(hAttacker, hAttacked, bEventWhenDone);
native Bot_FacePt(hBot, vecPos, nTrackPercent, nTimeOut, bEventWhenDone);
native Bot_FaceE(hBot, hEntityLookAt, nTrackPercent, nTimeOut, bEventWhenDone);
native Bot_FacePlayer(hBot, hPlayer, nTimeOut, bEventWhenDone);

// nPerceptorID (0 = Eyes, 1 = Ears, 2 = Touch, 3 = Radio)
native Bot_TurnOnPercep(hBot, nPerceptorID);
native Bot_TurnOffPercep(hBot, nPerceptorID);
native Bot_UsePercep(hBot, nPerceptorID);
native Bot_IgnorePercep(hBot, nPerceptorID);
native Bot_IsPercepOn(hBot, nPerceptorID);
native Bot_IsPercepInUse(hBot, nPerceptorID);

native Bot_FollowLeader(hBotFollower, hEntityLeader, bIsFollowing);
native Bot_SetBaseSpeed(hBot, nSpeedPercent);
native Bot_ClrAttackSpecs(hBot, bResetCurrentAttack);
native Bot_SetAttackSpecs(hBot, nNormalRuleSet, nAlternateRuleSet, nAlternateRuleSetOdds, nAttackMaxDistFromOrigin, nStayPutDist, nAttackSpeedMin, nAttackSpeedMax, bResetCurrentAttack);

native Bot_LoadTalk(sBTA[], nNumToAlloc);
native Bot_Talk(hBot, sBTA[], hEntityLookAt, bStopFirst);

native Ai_EnableUnarmedPlayerRule();
native Ai_DisableUnarmedPlayerRule();
native Ai_IsUnarmedPlayerRuleEnabled();
native Ai_CountEnemiesNear(hEntity, hNearbyEntity, fWithinDist);
native Ai_CountFriendsNear(hEntity, hNearbyEntity, fWithinDist);
native Bot_CanSeeBot(hBotSeeker, hBotSeeked);

native Bot_GetAnimPos();

native Bot_AttachAnim(hBot, hAnim, hAnimIdx);
native Bot_DetachAnim(hBot, hAnimIdx);
native Bot_MaskUBody(hBot, hAnimIdx, bDriveBonesInList);
native Bot_MaskLBody(hBot, hAnimIdx, bDriveBonesInList);

native Bot_LoadAnim(sMtxName[]);
native Bot_PlayAnim(hBot);

native Bot_TurnAround(hBot, bTurnAround);
native Bot_IsTurnedAround(hBot);
native Bot_SpotLightOn(hBot, bTurnOn);

native Bot_ZomStartForming(hZombieBot);
native Bot_ZomFloatPieces(hZombieBot);
native Bot_ZomCollapse(hZombieBot);

native Bot_PossessExit(hBot, bCanBeExited);

// @param nCtrlParam (0 = never, 1 = auto, 2 = onaction)
native Bot_SetBuddyCtrl(hBot, nCtrlParam);

// @Warning Will not work if a Recruiter grenade is not in the level or Glitch's inventory
native Bot_Recruit(hRecruiter, hRecruited); 

//═══════════════════════════════════════════════════════════════ BotTalk

native BTI_AcquireBTI();
native BTI_ReleaseBTI(hBTI);
// @param sBotTalkName Filename of bottalk .csv file produced by BotTalkInator
native BTI_InitBTI(hBTI, hBot, sBotTalkName[]);
native BTI_PlayBTI(hBTI, hBot);
native BTI_IsBTIPlaying(hBTI);
native BTI_SetAudio2D(hBTI);
native BTI_SetAudioRadius(hBTI, fRadius);
native BTI_DuckAudWhenPlay(hBTI, bIsDuckAudio);

//═══════════════════════════════════════════════════════════════ Console

// Switch to turn console On/Off. Console is On by default
native Console_Enable(hConsole); 

//═══════════════════════════════════════════════════════════════ Player

// Same as E_Find("Player0") AKA Player 1, commonly used in Single Player
native Bot_GetPlayer();
native Bot_FreezePlayer();
native Bot_UnfreezePlayer();

native G_GiveToGlitch(sGoodieName[]);	
native G_NotifyGoodieUsed(sGoodieName[]);	
native G_IsInInventory(sGoodieName[]);	

native BotBlink_AbortScope(bIsImmediate);
native BotGlitch_FallDown();

// NOT THE PLAYER but grouping in here b/c it's technically a Player Entity
native BotBlink_Acquire();
native BotBlink_Release(hBotGlitch);
native BotBlink_Init1(hBotGlitch, vecPos);

//═══════════════════════════════════════════════════════════════ Vehicle

native Vehicle_SetPath(hVehicle, hSpline);	
native Vehicle_ClearPath(hVehicle);	
native Vehicle_SetPlayer(hVehicle, hPlayer);	
native Vehicle_Driveable(hVehicle, bIsDrivable);	
native Vehicle_PlayerDrive(hVehicle, bIsDrivable);	
native Vehicle_PlayerGun(hVehicle, hPlayer);	
native Vehicle_EjectDriver(hVehicle);	
native Vehicle_EjectGunner(hVehicle);	
native Vehicle_DriverExit(hVehicle, bCanExit);	
native Vehicle_GunnerExit(hVehicle, bCanExit);	
// @oaram nSpeedPercent (0 - 100) Percentage of max speed
native Vehicle_MaxSpeed(hVehicle, nSpeedPercent);	
native Vehicle_GetSpeed(hVehicle);	

//═══════════════════════════════════════════════════════════════ Doors / Lifts

native Door_Find(sDoorName[]);
native Door_IsValid(hDoor);
native Door_GotoPos(hDoor, nNewPos);
native Door_GetUnitPos(hDoor);
native Door_GetUnitPosMap(hDoor);
native Door_SetLock(hDoor, bIsLocked);
native Door_SnapToPos(hDoor, nNewPos);

//═══════════════════════════════════════════════════════════════ Splines, Vectors & Quaternions

native FV3Points1_Init1(hPointPath, sPathName[], fTotalTime, bAutoStart);
native FV3Points2_Init1(hPointPath, sPathName[], fTotalTime, bAutoStart);

native FQuatSLERP_Init1(hQuatSLERP, hStartEntity, hEndEntity, fTotalTime, bAutoStart);

native SActor_Init(hSActor, szSplineName[], fTotalTime, hMEntity, bAutoStart);
native SActor_SetTimePos(hSActor, fTimePos);
native SActor_GetTimePos(...);
native SActor_Reset(hSActor, bAutoStart);
native SActor_Start(hSActor);
native SActor_Stop(hSActor);
native SActor_IsDone(hSActor);
// GSActor (General Spline Actor) specific functions
native GSActor_Acquire(...);
// HSActor (Horizontal Spline Actor) specific functions
native HSActor_Acquire(...);
// SSActor (Swinging Spline Actor) specific functions
native SSActor_Acquire(...);
// SOSActor (Static Orientation Spline Actor) specific functions
native SOSActor_Acquire(...);

//═══════════════════════════════════════════════════════════════ Timer

native Timer_AcquireETimer();
native Timer_ReleaseETimer(hETimer);
native Timer_SetETimer(hETimer, fTime);
native Timer_Set(fTime);
native Timer_IsDone();
native Timer_ShowIcon(hETimer);
native Timer_HideIcon();

//═══════════════════════════════════════════════════════════════ HUD

native HUD_StartCAMsg(hAudio);

native HUD_RadioStartBank(...);
native HUD_RadioStartStrm(...);
native HUD_RadioStop(...);
native HUD_RadioIsPlaying(...);

native HUD_SetMissionText(nMissionTextIndex);
native HUD_GetMissionIndex();

//═══════════════════════════════════════════════════════════════ Music / SFX

native Music_Play(sWvsName[]);
native Music_PlayEx(sWvsName[], nVolume, bFadeIn);
// These two are test functions, use Music_Play and Music_PlayEx instead
native Music_PlayDefault();
native Music_PlayDefaultEx(nVolume, bFadeIn);
native Music_Stop();	

native Audio_GetSFXHandle(sAudioName[]);
native Audio_SetAmbientSFX(...);
native Audio_GetAmbientSFX(...);
native Audio_SetAmbientVol(...);
native Audio_GetAmbientVol(...);
native Audio_SetAmbientRad(...);
native Audio_GetAmbientRad(...);
native Audio_PlayAmbient(hSFXname);
native Audio_StopAmbient(...);
native Audio_Play2DSound(hSFXName, nVolume);

native StreamingSfx_Play(sSongName[]);
native StreamingSfx_PlayEx(sGoodieName[], nVolume, bFadeIn);	
	
native Speech_Play(sSongName[], nVolume, bLoops);	
native Speech_Stop(...);

//═══════════════════════════════════════════════════════════════ Movies

native Movie_GetHandle(sMovieName[]);
native Movie_Play(hMovie);
native Movie_PlayEx(hMovie, nVolumeLevel);
native Movie_Stop();

//═══════════════════════════════════════════════════════════════ Particles / Effects

native Particle_Find(sEntityName[]);
native Particle_Start(hParticle);
native Particle_Stop(hParticle);

native FX_Explosion_Find(sExplosionName[]);	
native FX_Explosion(hExplosion, hEntity);	

//═══════════════════════════════════════════════════════════════ Single Player

native Checkpoint_Save();

native Game_BeginCutScene(sTitle[]);
native Game_EndCutScene();
// @param sGoToLevel[] ("next" or "restart")
native Game_WinLevel(sGoToLevel[]);
native Game_DoPauseMode();

native Misc_GetDifficulty();

//═══════════════════════════════════════════════════════════════ Barter

native Barter_MoveToPoint(sPointName[]);	
native Barter_Remove(bFadeMusic);	
native Barter_SetAttract(nWhichTable, fAttractMusicRadius, fAttractSpeechRadius);	

//═══════════════════════════════════════════════════════════════ Goodie Bag
// (GI) Goodie Instance, (GB) Goodie Bag

// These operate on the goodie bag as a whole.
native GB_GetNumGIs(...);
native GB_GetProb(...);
native GB_SetProb(...);

// These operate on specific goodie instances.
native GB_GetGoodieType(...);
native GB_SetGoodieType(...);
native GB_GetGoodieQuant1(...);
native GB_SetGoodieQuant1(...);
native GB_GetGoodieQuant2(...);
native GB_SetGoodieQuant2(...);
native GB_GetGoodieProb(...);
native GB_SetGoodieProb(...);

//═══════════════════════════════════════════════════════════════ AlarmNet / SpawnNet

native E_AlarmNetFind(sAlarmNetName[]);
// @param hBotToAttack Usually the player. Leave as 0 for no attack target
native E_TurnOnAlarmNet(hAlarmNet, hBotToAttack);
native E_TurnOffAlarmNet(hAlarmNet);
native E_IsAlarmNetOn(hAlarmNet);

native E_SpawnNetFind(sSpawnNetName[]);
native E_TurnOnSpawnNet();
native E_TurnOffSpawnNet();
// Function only uses 1 param but requires 2?
// Also Spawn Nets ARE NOT entities, leaving again
native E_GetSpawnNetDefCon(hSpawnNet, junk);
native E_SetSpawnNetDefCon(hSpawnNet, nDefConLevel);

//═══════════════════════════════════════════════════════════════ Mesh Entity

native ME_Acquire();
native ME_Release();
native ME_Find(sMeshEntityName[]);
native ME_IsValid(hMeshEntity);
native ME_AddToWorld(hMeshEntity);
native ME_RemoveFromWorld(hMeshEntity);

native ME_Init1(hMeshEntity, hMesh);
native ME_Init2(hMeshEntity, hMesh, sMtxName[]);
native ME_AnimSelect(hMeshEntity, nAnimIdx);
native ME_SetAnimSpeed(hMeshEntity, fAnimSpeed);
native ME_GetAnimSpeed(hMeshEntity);
native ME_SetAnimClamp(hMeshEntity, bIsAnimClamped);
native ME_EnableAnim(hMeshEntity, bIsEnabled);
native ME_GetUnitAnimPos(hMeshEntity);
native ME_GetAnimPos(hMeshEntity);
native ME_SetUnitAnimPos(hMeshEntity, fUnitAnimPos);
native ME_SetAnimPos(hMeshEntity, fAnimPos);
// Remain awake when player is away from Entity's cell
native ME_SetAlwaysWork(hMeshEntity, bIsAlwaysWork);

//═══════════════════════════════════════════════════════════════ Mesh Actor

native MeshActor_Acquire();
native MeshActor_Release(hMeshActor);
native MeshActor_IsValid(hMeshActor);
native MeshActor_Init(hMeshActor, hMeshEntity, vecPost, vecQuat);
native MeshActor_Activate(hMeshActor);
native MeshActor_Deactivat(hMeshActor);
native MeshActor_SetPosObj(hMeshActor, vecPos);
native MeshActor_SetQuatObj(hMeshActor, quatPos);

//═══════════════════════════════════════════════════════════════ Bot Actor

native BotActor_Acquire();
native BotActor_Release(hBotActor);
native BotActor_IsValid(hBotActor);
native BotActor_Init1(hBotActor, hBot);
native BotActor_Init2(hBotActor, hBot, hAnimInst, nAnimSlot);
native BotActor_Activate(hBotActor);
native BotActor_Deactivate(hBotActor);
native BotActor_SetPosObj(hBotActor, vecPos);
native BotActor_SetQuatObj(hBotActor, quatPos);
native BotActor_SetAnimMult(hBotActor, fAnimMult);

//═══════════════════════════════════════════════════════════════ Camera

native Cam_Init(vecPos, quatPos, fHalfFOV);
native Cam_Activate();
native Cam_Deactivate();
native Cam_Shake(fIntensity, fDuration);

native CamAnim_GetHandle(sCamName[]);
native CamAnim_Start(hCamera);
native CamAnim_StartEx(hCamera, bIsLetterboxed);
native CamAnim_StartEx2(hCamera, bIsLetterboxed, bIsAIDisabled);
native CamAnim_End();

// ??? Are these ever called?
native CamActor_Acquire(...);
native CamActor_Release(...);
native CamActor_IsValid(...);
native CamActor_Init(...);
native CamActor_Activate(...);
native CamActor_Deactivate(...);
native CamActor_SetPosObj(...);
native CamActor_SetQuatObj(...);

//═══════════════════════════════════════════════════════════════ Tacks

native Tack_Find(...);

native Tack_GetHealth(...);
native Tack_SetHealth(...);

native Tack_SetArmorProf(...);

native Tack_Enable(hTack, bIsEnabled);
native Tack_Remove(...);
native Tack_ToEntityStat(...);
native Tack_ToEntityDyn(...);
native Tack_ToPos(...);
native Tack_SetRange(...);

native Tack_IsEnabled(...);
native Tack_GetRangeMin(...);
native Tack_GetRangeMax(...);
native Tack_GetSnapped2Me(...);

native Tack_GetPhysEntity(...);

//═══════════════════════════════════════════════════════════════ Physics

native Phys_Reset(hEntity, bKickstartNet);
native Phys_Freeze(hEntity, bFreeze);
native Phys_Kickstart(...);
native Phys_Sleep(...);
native Phys_SetDampening(...);
native Phys_SetPrimeSecs(...);
native Phys_SetGravity(...);

native Phys_IsFrozen(...);
native Phys_IsSleeping(...);
native Phys_GetDampening(...);
native Phys_GetPrimeSecs(...);
native Phys_GetGravity(...);

native Phys_GetTackCount(...);
native Phys_GetTack(...);

//═══════════════════════════════════════════════════════════════ Debris
native Deb_RumbleShake(hEntity, bEnableRumbleShake);	
native Deb_GetRumbleShake(hEntity);	
native Deb_SetAutoShake(hEntity, fAutoShakeSecondsMin, fAutoShakeSecondsMax);	
native Deb_Shake(hEntity, fIntensity);	

//═══════════════════════════════════════════════════════════════ Obsolete
// Functions that once existed but became deprecated, keeping here for legacy reasons

//native DE_StartDestruct(...);
