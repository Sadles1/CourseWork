
#include "MessengerAccount.h"

void UMessengerAccount::ReceiveMsg(UMessengerChat* ToChat, const FMessage Msg)
{
	UMessengerChat* Chat = Chats[Chats.Find(ToChat)];
	if(Chat)
		Chat->AddMessage(Msg);
}
