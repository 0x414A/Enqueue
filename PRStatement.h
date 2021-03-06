#import <Foundation/Foundation.h>
@class PRDb;
@class PRConnection;

@interface PRStatement : NSObject
- (id)initWithString:(NSString *)string bindings:(NSDictionary *)bindings columns:(NSArray *)columns connection:(PRConnection *)connection;
- (id)initWithString:(NSString *)string bindings:(NSDictionary *)bindings columns:(NSArray *)columns db:(PRDb *)db;
@property (readonly) NSString *statement;
@property (nonatomic, strong) NSDictionary *bindings;
@property (readonly) NSArray *columns;
- (BOOL)zExecute:(NSArray **)outValue;
@end
