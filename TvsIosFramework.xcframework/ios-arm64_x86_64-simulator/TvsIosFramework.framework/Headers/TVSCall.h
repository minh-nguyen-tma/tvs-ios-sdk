//
//  TVSCall.h
//  T-Building
//
//  Created by Minh Nguyen on 09/09/2022.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


#define kMessageTypeRegister @"REGISTER"
#define kMessageTypeInvite @"video-invite"
#define kMessageTypeAnswer @"video-answer"
#define kMessageTypeEnd @"video-end"
#define kMessageTypeCancel @"video-cancel"
#define kMessageTypeReject @"video-reject"
#define kMessageTypeOffer @"video-offer"
#define kMessageTypeText @"text-message"
#define kMessageTypeKeepAlive @"keep-alive"

@protocol TVSCallDelegate;

API_AVAILABLE(ios(6.0))
@interface TVSCall : NSObject

@property (nonatomic, strong) NSUUID *uuid;
@property (nonatomic, strong) NSString *callId;
@property (nonatomic, strong) NSString *from;
@property (nonatomic, strong) NSString *to;
@property (nonatomic, strong) NSString *targetType;
@property (nonatomic, strong) NSString *remoteDisplayName;
@property (nonatomic, strong) NSString *remoteIdentity;
@property (nonatomic, strong) NSString *peerConnectionConfig;
@property (nonatomic, strong) NSString *remoteSdp;
@property (nonatomic, strong) NSString *remoteCandidates;
@property (nonatomic) BOOL isIncomingCall;

@property (nonatomic, weak) id <TVSCallDelegate> delegate;

- (instancetype)initWithId:(NSString*)callId andToken:(NSString*)accessToken;
- (void)start:(NSString *)offerSdp candidates:(NSString *)candidates agent:(NSString *)agent;
- (void)reject;
- (void)end;
- (void)accept:(NSString *)answerSdp candidates:(NSString *)candidates;
- (void)acceptUpdateMediaRequest:(NSString *)localSdp;
- (void)requestUpdateMedia:(NSString *)offerSdp candidates:(NSString *)candidates;
- (void)sendTextMessage:(NSString *)message targetType:(NSString *)targetType;

@end

@protocol TVSCallDelegate <NSObject>
- (void)callDidCreate:(TVSCall*)call
withPeerConnectionConfig:(NSString*)peerConnectionConfig
             offerSdp:(NSString*)offerSdp
           candidates:(NSString*)candidates;
- (void)callDidStart:(TVSCall*)call;
- (void)callDidFail:(TVSCall*)call code:(NSInteger)code reason:(NSString*)reason errorCode:(NSNumber* _Nullable)errorCode;
- (void)callDidEnd:(TVSCall*)call code:(NSInteger)code reason:(NSString*)reason;
- (void)callNegotiationNeeded:(TVSCall*)call sdp:(NSString*)sdp candidates:(NSString*)candidates;
- (void)call:(TVSCall*)call receivedRemoteCandidate:(NSString*)candidate;
- (void)call:(TVSCall*)call receivedTextMessage:(NSString*)message;
@end


NS_ASSUME_NONNULL_END
