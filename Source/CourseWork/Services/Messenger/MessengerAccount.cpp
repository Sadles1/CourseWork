
#include "MessengerAccount.h"
#include "Chat/Message.h"
#include "Chat/MessengerChat.h"

void UMessengerAccount::SendMsg(UMessengerChat* ToChat, const FMessage Msg)
{
	UMessengerChat* Chat = Chats[Chats.Find(ToChat)];
	if(Chat)
		Chat->AddMessage(Msg);
}

void UMessengerAccount::SetSecretQuestionCategory(const TEnumAsByte<ESecretQuestion> SecretQuestion)
{
	SecretQuestionCategory = SecretQuestion;
}