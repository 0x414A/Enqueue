#import "PRTask.h"


@implementation PRTask

#pragma mark - Initialization

- (id)init {
    if (!(self = [super init])) {return nil;}
    _shouldCancel = NO;
    _background = YES;
    return self;
}

+ (PRTask *)task {
    return [[PRTask alloc] init];
}


#pragma mark - Accessors

@synthesize title = _title,
percent = _percent,
shouldCancel = _shouldCancel,
background = _background;

@end
