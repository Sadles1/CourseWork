
#include "MessengerAccount.h"

void UMessengerAccount::SendMsg(UMessengerChat* ToChat, const FMessage Msg)
{
	UMessengerChat* Chat = Chats[Chats.Find(ToChat)];
	if(Chat)
		Chat->AddMessage(Msg);
}
