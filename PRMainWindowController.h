#import <Cocoa/Cocoa.h>
#import "PRPlaylists.h"


@class PRCore, PRDb, PRPlaylists, PRNowPlayingController, PRFolderMonitor, PRTaskManagerViewController,
PRNowPlayingViewController, PRControlsViewController, PRLibraryViewController, PRPreferencesViewController, 
PRPlaylistsViewController, PRHistoryViewController, PRSongViewController, PRGradientView, 
MAAttachedWindow, PRMainMenuController, YRKSpinningProgressIndicator, PRStringFormatter;

typedef enum {
    PRLibraryMode,
    PRPlaylistsMode,
    PRPreferencesMode,
    PRHistoryMode,
    PRSongMode,
} PRMode;

@interface PRMainWindowController : NSWindowController //<NSMenuDelegate, NSWindowDelegate>
{
    IBOutlet NSView *centerSuperview;
    IBOutlet NSView *controlsSuperview;
    IBOutlet NSView *nowPlayingSuperview;
    IBOutlet NSButton *songButton;
    IBOutlet NSButton *libraryButton;
    IBOutlet NSButton *playlistsButton; 
    IBOutlet NSButton *historyButton;
    IBOutlet NSButton *preferencesButton;
    IBOutlet NSSearchField *searchField;
    
    IBOutlet NSTextField *progressTextField;
    IBOutlet YRKSpinningProgressIndicator *progressIndicator;
    
    IBOutlet NSButton *infoButton;
    IBOutlet NSButton *listModeButton;
    IBOutlet NSButton *albumListModeButton;
    
    IBOutlet PRGradientView *toolbarView;
    IBOutlet PRGradientView *toolbarRightBorder;
    IBOutlet PRGradientView *mainDivider;
    IBOutlet PRGradientView *divider;
    IBOutlet PRGradientView *divider2;
    IBOutlet PRGradientView *divider5;
    
    IBOutlet NSTextField *playlistTitle;
    	
    PRStringFormatter *stringFormatter;
    PRMode currentMode;
    int currentPlaylist;
    id currentViewController;
    
    // View controllers
    PRMainMenuController *mainMenuController;
    PRTaskManagerViewController *taskManagerViewController;
    PRSongViewController *songViewController;
    PRLibraryViewController *libraryViewController;	
    PRHistoryViewController *historyViewController;
    PRPlaylistsViewController *playlistsViewController;
    PRPreferencesViewController *preferencesViewController;	
    PRNowPlayingViewController *nowPlayingViewController;
    PRControlsViewController *controlsViewController;
	
    PRCore *core;
    PRDb *db;
    PRNowPlayingController *now;
    PRFolderMonitor *folderMonitor;
}

// ========================================
// Initializer

- (id)initWithCore:(PRCore *)core_;

// ========================================
// Accessors

@property (readonly) PRSongViewController *songViewController;
@property (readonly) PRLibraryViewController *libraryViewController;
@property (readonly) PRHistoryViewController *historyViewController;
@property (readonly) PRPlaylistsViewController *playlistsViewController;
@property (readonly) PRPreferencesViewController *preferencesViewController;
@property (readonly) PRNowPlayingViewController *nowPlayingViewController;
@property (readonly) PRControlsViewController *controlsViewController;
@property (readonly) PRTaskManagerViewController *taskManagerViewController;

// Sets the current mode and playlist. Propogates changes to view controllers.
@property (readwrite) PRMode currentMode;
@property (readwrite) PRPlaylist currentPlaylist;
@property (readwrite) BOOL showsArtwork;

@property (readwrite) BOOL progressHidden;
@property (readwrite, retain) NSString *progressTitle;
@property (readwrite) float progressValue;

// ========================================
// UI

- (void)updateUI;
- (void)find;

@end


@interface PRMainWindowController ()

// ========================================
// Update

// Updates searchField
- (void)playlistDidChange:(NSNotification *)notification;

// Updates segmentedControl
- (void)libraryViewModeDidChange:(NSNotification *)notification;

// update subBar
- (void)libraryViewDidChange:(NSNotification *)notification;

- (void)playlistsDidChange:(NSNotification *)notification;

// ========================================
// Accessors

// Accessors for search field and segmented control bindings
- (NSString *)search;
- (void)setSearch:(NSString *)newSearch;
- (int)libraryViewMode;
- (void)setLibraryViewMode:(int)libraryViewMode;

@end