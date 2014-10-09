#ifndef ASTERISKMANAGER_H
#define ASTERISKMANAGER_H

#include <QTcpSocket>
#include <QMetaEnum>

#define yes "yes"
#define no "no"

typedef qint8 boolean;
typedef QString answer;

class AsteriskManager : public QTcpSocket
{
	Q_OBJECT

	Q_ENUMS(Response)
	Q_ENUMS(Event)

public:
	enum Response {
		Success,
		Error,
		Follows
	};

	enum Event {
		AgentCalled,
		AgentComplete,
		AgentConnect,
		AgentDump,
		Agentlogin,
		Agentlogoff,
		AgentRingNoAnswer,
		Alarm,
		AlarmClear,
		Bridge,
		BridgeAction,
		BridgeExec,
		ChanSpyStart,
		ChanSpyStop,
		ConfbridgeEnd,
		ConfbridgeJoin,
		ConfbridgeLeave,
		ConfbridgeStart,
		ConfbridgeTalking,
		DAHDIChannel,
		Dial,
		DNDState,
		DTMF,
		ExtensionStatus,
		FullyBooted,
		Hangup,
		HangupHandlerPop,
		HangupHandlerPush,
		HangupHandlerRun,
		HangupRequest,
		Hold,
		Join,
		Leave,
		LocalBridge,
		LogChannel,
		Masquerade,
		MeetmeEnd,
		MeetmeJoin,
		MeetmeLeave,
		MeetmeMute,
		MeetmeTalking,
		MeetmeTalkRequest,
		MessageWaiting,
		ModuleLoadReport,
		NewAccountCode,
		NewCallerid,
		Newchannel,
		Newexten,
		NewPeerAccount,
		Newstate,
		OriginateResponse,
		ParkedCall,
		ParkedCallGiveUp,
		ParkedCallTimeOut,
		Pickup,
		PresenceStatus,
		QueueCallerAbandon,
		QueueMemberAdded,
		QueueMemberPaused,
		QueueMemberPenalty,
		QueueMemberRemoved,
		QueueMemberRinginuse,
		QueueMemberStatus,
		Rename,
		Shutdown,
		SoftHangupRequest,
		SpanAlarm,
		SpanAlarmClear,
		UnParkedCall,
		UserEvent,
		VarSet
	};

	explicit AsteriskManager(QObject *parent = 0);

	QString actionAbsoluteTimeout();
	QString actionAgentLogoff();
	QString actionAgents();
	QString actionAGI();
	QString actionAOCMessage();
	QString actionAtxfer();
	QString actionBridge();
	QString actionChallenge();
	QString actionChangeMonitor();
	QString actionCommand();
	QString actionConfbridgeKick();
	QString actionConfbridgeList();
	QString actionConfbridgeListRooms();
	QString actionConfbridgeLock();
	QString actionConfbridgeMute();
	QString actionConfbridgeSetSingleVideoSrc();
	QString actionConfbridgeStartRecord();
	QString actionConfbridgeStopRecord();
	QString actionConfbridgeUnlock();
	QString actionConfbridgeUnmute();
	QString actionCoreSettings();
	QString actionCoreShowChannels();
	QString actionCoreStatus();
	QString actionCreateConfig();
	QString actionDAHDIDialOffhook();
	QString actionDAHDIDNDoff();
	QString actionDAHDIDNDon();
	QString actionDAHDIHangup();
	QString actionDAHDIRestart();
	QString actionDAHDIShowChannels();
	QString actionDAHDITransfer();
	QString actionDataGet();
	QString actionDBDel();
	QString actionDBDelTree();
	QString actionDBGet();
	QString actionDBPut();
	QString actionEvents();
	QString actionExtensionState();
	QString actionFilter();
	QString actionFilterList();
	QString actionGetConfig();
	QString actionGetConfigJSON();
	QString actionGetvar();
	QString actionHangup(QString channel, uint cause = 0);
	QString actionIAXnetstats();
	QString actionIAXpeerlist();
	QString actionIAXpeers();
	QString actionIAXregistry();
	QString actionJabberSend();
	QString actionJabberSendResJabber();
	QString actionJabberSendResXmpp();
	QString actionListCategories();
	QString actionListCommands();
	QString actionLocalOptimizeAway();
	QString actionLogin(QString username, QString secret = QString());
	QString actionLogoff();
	QString actionMailboxCount();
	QString actionMailboxStatus();
	QString actionMeetmeList();
	QString actionMeetmeListRooms();
	QString actionMeetmeMute();
	QString actionMeetmeUnmute();
	QString actionMessageSend();
	QString actionMixMonitor();
	QString actionMixMonitorMute();
	QString actionModuleCheck();
	QString actionModuleLoad();
	QString actionMonitor();
	QString actionMuteAudio();
	QString actionOriginate(QString channel,
							QString exten = QString(),
							QString context = QString(),
							uint priority = 0,
							QString application = QString(),
							QString data = QString(),
							uint timeout = 0,
							QString callerID = QString(),
							QVariantMap variables = QVariantMap(),
							QString account = QString(),
							boolean earlyMedia = -1,
							boolean async = -1,
							QStringList codecs = QStringList());
	QString actionPark();
	QString actionParkedCalls();
	QString actionParkinglots();
	QString actionPauseMonitor();
	QString actionPing();
	QString actionPlayDTMF();
	QString actionPresenceState();
	QString actionPRIShowSpans();
	QString actionQueueAdd(QString queue,
						   QString interface,
						   uint penalty = 0,
						   boolean paused = -1,
						   QString memberName = QString(),
						   QString stateInterface = QString());
	QString actionQueueLog();
	QString actionQueueMemberRingInUse();
	QString actionQueuePause(QString interface, boolean paused, QString queue = QString(), QString reason = QString());
	QString actionQueuePenalty();
	QString actionQueueReload();
	QString actionQueueRemove(QString queue, QString interface);
	QString actionQueueReset();
	QString actionQueueRule();
	QString actionQueues();
	QString actionQueueStatus(QString queue = QString(), QString member = QString());
	QString actionQueueSummary();
	QString actionRedirect();
	QString actionReload();
	QString actionSendText();
	QString actionSetvar();
	QString actionShowDialPlan();
	QString actionSIPnotify();
	QString actionSIPpeers();
	QString actionSIPpeerstatus();
	QString actionSIPqualifypeer();
	QString actionSIPshowpeer(QString peer);
	QString actionSIPshowregistry();
	QString actionSKINNYdevices();
	QString actionSKINNYlines();
	QString actionSKINNYshowdevice();
	QString actionSKINNYshowline();
	QString actionStatus();
	QString actionStopMixMonitor();
	QString actionStopMonitor();
	QString actionUnpauseMonitor();
	QString actionUpdateConfig();
	QString actionUserEvent();
	QString actionVoicemailUsersList();
	QString actionWaitEvent();

private:
	QMetaEnum responseEnum, eventEnum;
	QVariantMap packetBuffer;

	QString valueToString(QVariant value);
	QVariant stringValue(QString string);
	void insertNotEmpty(QVariantMap *headers, QString key, QVariant value);
	void dispatchPacket();
	QString sendAction(QString action, QVariantMap headers = QVariantMap());

private slots:
	void onReadyRead();

signals:
	void connected(QString version);
	void responseSent(AsteriskManager::Response response, QVariantMap headers, QString actionID);
	void eventGenerated(AsteriskManager::Event event, QVariantMap headers);
};

#endif // ASTERISKMANAGER_H